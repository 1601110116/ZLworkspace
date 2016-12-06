//============================================================================
// Name        : ZLOMP.cpp
// Author      : ZL
// Version     :
// Copyright   : ZL-CSPIC
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <HostGrid.h>
#include <Visualize.h>
#include <GLEnvironment.h>

using namespace std;

int main(int argc, char**argv){

	HostGrid* grid=new HostGrid(1152,1,1,3);

	InitGLEnvironment();

	Visualize* stage=new Visualize(grid);

	InitStage(stage);

	return 0;
}
