//============================================================================
// Name        : Transmitter.cpp
// Author      : ZL
// Version     :
// Copyright   : ZL-CSPIC
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <inet.h>
#include <pthread.h>
using namespace std;

#define Nodes 3

int reportPort[Nodes];
int hostPort;

pthread_t recv_thread_handler,send_thread_handler;
pthread_mutex_t S_mutex,R_mutex;

void* recv_thread(void *p);
void* send_thread(void *p);

bool collect(int src);
bool report();

double* ParticleBuffer;
double* VertexBuffer;
int particles,vertexes;
int dest;

int main() {

	cout<<"Transmitter for LePlasma, ZL Studio 2016"<<endl;

	pthread_mutex_init(&R_mutex,NULL);
	pthread_mutex_init(&S_mutex,NULL);

	pthread_mutex_lock(&S_mutex);

	pthread_create(&recv_thread_handler,NULL,&recv_thread,NULL);
	pthread_create(&send_thread_handler,NULL,&send_thread,NULL);

	pthread_join(recv_thread_handler,NULL);

}

void* recv_thread(void* p){
	int inSocket=openListening(TRANSMITTER_IN_PORT);
	bool workersOnline;
	while(true){
		//Smart Align: let the cline ID the same as MPI ID
		int swap;
		int MPI_ID;

		for (int i = 0; i < Nodes; ++i) {
			swap=acceptSocket(inSocket);

			Recv(swap,&MPI_ID,4);

			cout<<"Node "<<MPI_ID<<" online"<<endl;

			//Align port array with MPI ID
			reportPort[MPI_ID]=swap;
		}

		//Start
		cout<<"Start Transmitting"<<endl;

		workersOnline=true;

		while(workersOnline){

			for (int i = 0; i < Nodes; ++i) {
				workersOnline=collect(i);
				if(!workersOnline)break;
			}
		}

		pthread_mutex_unlock(&R_mutex);

		cout<<"Workers offline"<<endl;
	}
}

void* send_thread(void* p){
	int outSocket=openListening(TRANSMITTER_OUT_PORT);
	bool workersOnline;
	while(true){
		//Smart Align: let the cline ID the same as MPI ID

		hostPort=acceptSocket(outSocket);

		cout<<"Host online"<<endl;

		pthread_mutex_unlock(&R_mutex);

		//Start

		workersOnline=true;

		while(workersOnline){

			workersOnline=report();
			if(!workersOnline)break;
		}

		///restore
		if(ParticleBuffer!=NULL)delete ParticleBuffer;
		if(VertexBuffer!=NULL)delete VertexBuffer;

		cout<<"Host offline"<<endl;
	}
}
bool collect(int src){
	int p_n,v_n,Len;

	//cout<<"receiving from "<<src;

	/*****Particles*****/
	if(!Recv(reportPort[src],&p_n,4))return false;

	Len=p_n*6;

	double* p_buffer=new double[Len];

	if(!Recv(reportPort[src],p_buffer,Len*sizeof(double)))return false;


	/*****Vertexes*****/
	if(!Recv(reportPort[src],&v_n,4))return false;

	Len=v_n*6;

	double* v_buffer=new double[Len];

	if(!Recv(reportPort[src],v_buffer,Len*sizeof(double)))return false;


	//cout<<" complete."<<endl;

	/*****Send*****/

	pthread_mutex_lock(&R_mutex);

	//Swap buffer

	dest=src;

	particles=p_n;

	vertexes=v_n;

	ParticleBuffer=p_buffer;

	VertexBuffer=v_buffer;

	pthread_mutex_unlock(&S_mutex);

	return true;

}

bool report(){
	int realLength,chk;

	pthread_mutex_lock(&S_mutex);

	//cout<<"sending...";

	send_data(hostPort,dest);

	/*****Particles*****/

	send_data(hostPort,particles);

	realLength=particles*6*sizeof(double);

	chk=send(hostPort,ParticleBuffer,realLength,0);

	if(chk<realLength)return false;

	/*****Vertexes*****/

	send_data(hostPort,vertexes);

	realLength=vertexes*6*sizeof(double);

	chk=send(hostPort,VertexBuffer,realLength,0);

	if(chk<realLength)return false;


	delete ParticleBuffer;
	delete VertexBuffer;

	//cout<<"complete."<<endl;

	pthread_mutex_unlock(&R_mutex);

	return true;

}
