/*
 * GraphReader.h
 *
 *  Created on: May 1, 2016
 *      Author: zlstudio
 */

#ifndef GRAPHREADER_H_
#define GRAPHREADER_H_

#include <Plot.h>
#include <Stage.h>
#include <TextField.h>



using namespace std;

class GraphReader: public Stage{
	public:
		GraphReader();
		virtual ~GraphReader();

		Plot Graph;

		double **table;
		double **table2;

		int W,H;

		TextField output;

		void mouseDown_evt(const MouseEvent& evt);
		void mouseWheel_evt(const MouseEvent& evt);
		void enterFrame_evt(const Event& evt);
};

#endif /* GRAPHREADER_H_ */
