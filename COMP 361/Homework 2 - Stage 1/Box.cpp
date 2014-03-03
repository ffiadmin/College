/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Box object on display. 
*/

#include "Box.h"


Box::Box(Cube* renderer, int xLoc, int zLoc, int yRotation, float xScale, float yScale, float zScale) : renderer(renderer) {
	graph = new Graph(renderer);
	graph->xLoc = xLoc;
	graph->yLoc = 0;
	graph->zLoc = zLoc;
	graph->yRotation = yRotation;
	graph->xScale = xScale;
	graph->yScale = yScale;
	graph->zScale = zScale;
}

Box::~Box() {
	delete graph;
}

void Box::draw() {
	graph->visit();
}