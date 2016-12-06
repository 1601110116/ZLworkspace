/*
 * GraphReader.cpp
 *
 *  Created on: May 1, 2016
 *      Author: zlstudio
 */

#include <Event.h>
#include <GL/freeglut_std.h>
#include <GraphReader.h>
#include <cmath>
#include <fstream>
#include <sstream>

int current=0;


GraphReader::GraphReader():Stage("Graph",100,100,600,600),
		Graph(580,500,"x","E"),W(1152),H(10000),output()
{

	table=new double*[H];
	for (int i = 0; i < H; ++i) {
		table[i]=new double[W];
	}

	table2=new double*[H];
	for (int i = 0; i < H; ++i) {
		table2[i]=new double[W];
	}


	ifstream file1,file2;
	file1.open("Report 2016_05_19_17_35.output");
	//file2.open("LePlasma_0.output");

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			file1>>table[i][j];
			//table[i][j]+=5*sin(double(j)/W*M_PI*2);
			//file2>>table2[i][j];
		}
	}

	file1.close();
	//file2.close();

	Graph.x=10;
	Graph.y=20;

	Graph.setCoordinate(PlotRange{0,W,-0.00001,0.00001});
	addChild(Graph);

	output.setTextStyle(GLUT_BITMAP_HELVETICA_12,0x009900);
	output.y=525;
	output.x=10;
	addChild(output);

	addEventListener(MOUSE_WHEEL,&EventListener::mouseWheel_evt);
	addEventListener(MOUSE_DOWN,&EventListener::mouseDown_evt);
	addEventListener(ENTER_FRAME,&EventListener::enterFrame_evt);
}

GraphReader::~GraphReader() {
	// TODO Auto-generated destructor stub
}

void GraphReader::mouseDown_evt(const MouseEvent& evt){

}

void GraphReader::mouseWheel_evt(const MouseEvent& evt){
	current+=evt.delta;
	if(current<0)current=0;
	if(current>=H)current=H-1;
	Graph.trackData1D(table[current],W);
	Graph.trackData1D2(table2[current],W);

	ostringstream out;
	out<<"frame "<<current;

	output.setText(out.str());
}

void GraphReader::enterFrame_evt(const Event& evt){
	current++;
	if(current>=H)current=0;
	Graph.trackData1D(table[current],W);
	Graph.trackData1D2(table2[current],W);

	ostringstream out;
	out<<"frame "<<current<<endl;

	output.setText(out.str());
}
