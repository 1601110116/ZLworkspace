/*
 * GraphVisualizer.cpp
 *
 *  Created on: May 1, 2016
 *      Author: zlstudio
 */

#include <iostream>

#include <vector>

#include <GLEnvironment.h>
#include <GraphReader.h>

using namespace std;

int main(){


	InitGLEnvironment();

	GraphReader* reader=new GraphReader();

	InitStage(reader);

}
