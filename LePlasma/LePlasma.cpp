//============================================================================
// Name        : LePlasma.cpp
// Author      : ZL
// Version     :
// Copyright   : ZL-CSPIC
// Description : Plasma
//============================================================================


#include <omp.h>

#include <iostream>
#include "include/Case.h"
#include "include/UniformE.h"
#include "include/RunManager.h"

using namespace std;

////////////////////////////////////////////////////////
////
////    LePlasma for calculate only
////
/////////////////////////////////////////////////////////

int main(int argc, char**argv){


#if MPI_PARALLEL
	MPI_Init(&argc, &argv);

	//omp_set_num_threads(1);

	RunManager::MPI_Init_Prarllel();
#endif


	Case* myCase=new UniformE();

	RunManager *run = new RunManager(myCase);

	double t=omp_get_wtime();

	for (int i = 0; i < 8000; ++i) {

		if(RunManager::MPI_ID==0)cout<<"run "<<i<<endl;

		run->stepNext();
	}

	cout<<"Node "<<RunManager::MPI_ID<<" Total Time: "<<omp_get_wtime()-t<<endl;


#if MPI_PARALLEL
	MPI_Finalize();
#endif

	return 0;
}
