/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Table object on display. 
*/

#pragma once

#include "Cube.h"
#include "Graph.h"

class Table {
public : 
	Table(Cube* renderer, int xLoc, int zLoc, int yRotation, float xScale, float yScale, float zScale);
	~Table(void);

	void draw();

private : 
	Cube* renderer;
	Graph* graph;
};