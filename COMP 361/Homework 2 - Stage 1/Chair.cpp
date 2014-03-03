/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Chair object on display. 
*/

#include "Chair.h"


Chair::Chair(Cube* renderer, int xLoc, int zLoc, int yRotation, float xScale, float yScale, float zScale) : renderer(renderer) {
//Leg 1
	graph = new Graph(renderer);
	graph->xLoc = (4 + xLoc);
	graph->yLoc = 0 * yScale;
	graph->zLoc = (4 + zLoc);
	graph->yRotation = yRotation;
	graph->xScale = 1 * xScale;
	graph->yScale = 5 * yScale;
	graph->zScale = 1 * zScale;

//Leg 2
	Graph* leg2 = new Graph(renderer);
	leg2->xLoc = (-4 + xLoc);
	leg2->yLoc = 0;
	leg2->zLoc = (4 + zLoc);
	leg2->yRotation = yRotation;
	leg2->xScale = 1 * xScale;
	leg2->yScale = 5 * yScale;
	leg2->zScale = 1 * zScale;

//Leg 3
	Graph* leg3 = new Graph(renderer);
	leg3->xLoc = (-4 + xLoc);
	leg3->yLoc = 0 * yScale;
	leg3->zLoc = (-4 + zLoc);
	leg3->yRotation = yRotation;
	leg3->xScale = 1 * xScale;
	leg3->yScale = 5 * yScale;
	leg3->zScale = 1 * zScale;

//Leg 4
	Graph* leg4 = new Graph(renderer);
	leg4->xLoc = (4 + xLoc);
	leg4->yLoc = 0 * yScale;
	leg4->zLoc = (-4 + zLoc);
	leg4->yRotation = yRotation;
	leg4->xScale = 1 * xScale;
	leg4->yScale = 5 * yScale;
	leg4->zScale = 1 * zScale;

//Base
	Graph* base = new Graph(renderer);
	base->xLoc = xLoc;
	base->yLoc = (1 * 5 * yScale) + 10;
	base->zLoc = zLoc;
	base->yRotation = yRotation;
	base->xScale = 5.0f * xScale;
	base->yScale = 0.2f;
	base->zScale = 5.0f * zScale;

//Back
	Graph* back = new Graph(renderer);
	back->xLoc = xLoc * xScale;
	back->yLoc = 1 * 5 * yScale;
	back->zLoc = (9 + zLoc) * zScale;
	back->yRotation = yRotation;
	back->xScale = 5.0f * xScale;
	back->yScale = 5.0f * yScale;
	back->zScale = 0.5f * zScale;

	graph->graft(leg2);
	graph->graft(leg3);
	graph->graft(leg4);
	graph->graft(base);
	graph->graft(back);
}

Chair::~Chair() {
	delete graph;
}

void Chair::draw() {
	graph->visit();
}