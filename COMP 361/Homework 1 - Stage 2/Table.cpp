/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Table object on display. 
*/

#include "Table.h"


Table::Table(Cube* renderer, int xLoc, int zLoc, int yRotation, float xScale, float yScale, float zScale) : renderer(renderer) {
//Leg 1
	graph = new Graph(renderer);
	graph->xLoc = (4.5 + xLoc) * xScale;
	graph->yLoc = 0 * yScale;
	graph->zLoc = (4.5 + zLoc) * zScale;
	graph->yRotation = yRotation;
	graph->xScale = 0.5f * xScale;
	graph->yScale = 5 * yScale;
	graph->zScale = 0.5f * zScale;

//Leg 2
	Graph* leg2 = new Graph(renderer);
	leg2->xLoc = (-4.5 + xLoc) * xScale;
	leg2->yLoc = 0 * yScale;
	leg2->zLoc = (4.5 + zLoc) * zScale;
	leg2->yRotation = yRotation;
	leg2->xScale = 0.5f * xScale;
	leg2->yScale = 5 * yScale;
	leg2->zScale = 0.5f * zScale;

//Leg 3
	Graph* leg3 = new Graph(renderer);
	leg3->xLoc = (-4.5 + xLoc) * xScale;
	leg3->yLoc = 0 * yScale;
	leg3->zLoc = (-4.5 + zLoc) * zScale;
	leg3->yRotation = yRotation;
	leg3->xScale = 0.5f * xScale;
	leg3->yScale = 5 * yScale;
	leg3->zScale = 0.5f * zScale;

//Leg 4
	Graph* leg4 = new Graph(renderer);
	leg4->xLoc = (4.5 + xLoc) * xScale;
	leg4->yLoc = 0 * yScale;
	leg4->zLoc = (-4.5 + zLoc) * zScale;
	leg4->yRotation = yRotation;
	leg4->xScale = 0.5f * xScale;
	leg4->yScale = 5 * yScale;
	leg4->zScale = 0.5f * zScale;

//Base
	Graph* base = new Graph(renderer);
	base->xLoc = xLoc * xScale;
	base->yLoc = 5 * yScale;
	base->zLoc = zLoc * zScale;
	base->yRotation = yRotation;
	base->xScale = 5 * xScale;
	base->yScale = 0.2f;
	base->zScale = 5 * zScale;

	graph->graft(leg2);
	graph->graft(leg3);
	graph->graft(leg4);
	graph->graft(base);
}

Table::~Table() {
	delete graph;
}

void Table::draw() {
	graph->visit();
}