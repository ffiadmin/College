/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Box object on display. 
*/

#pragma once

#include "Cube.h"
#include "Graph.h"

class Box {
public : 
	Box(Cube* renderer, int xLoc, int zLoc, int yRotation, float xScale, float yScale, float zScale);
	~Box(void);

	void draw();

private : 
	Cube* renderer;
	Graph* graph;
};