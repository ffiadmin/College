/* 
 Author: Oliver Spryn and Course Textbook
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This is the basic data type for the data structure for creating a scene graph.
*/

#pragma once

#include "Cube.h"
#include <vector>

using std::vector;

struct Graph {
public : 
	Graph(Cube* c) : c(c) {
		xLoc = yLoc = zLoc = 0;
		xScale = yScale = zScale = 0;
		yRotation = 0;
	}

	~Graph() {
		//Don't delete the Cube!

		for (int i = 0; i < children.size(); ++i) {
			delete children[i];
		}
	}

	Cube* c;
	vector<Graph*> children;

	float xLoc, yLoc, zLoc;
	float xScale, yScale, zScale;
	int yRotation;

	void graft(Graph* g) {
		children.push_back(g);
	}

	void visit() {
		c->applyTranslation(xLoc, yLoc, zLoc);
		c->applyRotation(Y, yRotation);
		c->applyScale(X, xScale);
		c->applyScale(Y, yScale);
		c->applyScale(Z, zScale);
		c->present();

		for (int i = 0; i < children.size(); ++i) {
			children[i]->visit();
		}
	}
};