/*
 * inet.h
 *
 *  Created on: Apr 13, 2016
 *      Author: zlstudio
 */

#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket

#include <unistd.h>
#include <cstdio>        // for printf
#include <cstdlib>        // for exit
#include <cstring>        // for bzero
#include <string>
#include <sys/socket.h>
#include <time.h>                //for time_t and time
#include <arpa/inet.h>


#define HOST_ADDRESS "192.168.14.1"
#define TRANSMITTER_ADDRESS "114.214.198.212"

//#define HOST_ADDRESS "127.0.0.1"
#define TRANSMITTER_IN_PORT 6197
#define TRANSMITTER_OUT_PORT 6198
#define SUPER_PORT 6197


#define recv_buffer(src,buffer) recv(src,buffer,sizeof(buffer),0);
#define recv_data(src,buffer) recv(src,&buffer,sizeof(buffer),0);

#define send_buffer(dest,buffer) send(dest,buffer,sizeof(buffer),0);
#define send_data(dest,buffer) send(dest,&buffer,sizeof(buffer),0);

int connectSocket(const char* serveraddr,int port);
int openListening(int port);
int acceptSocket(int listen_socket);

bool Recv(int socket, void* buffer, int len);
