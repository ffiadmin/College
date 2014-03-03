/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Chair object on display. 
*/

#include "Chair.h"


Chair::Chair(Cube* renderer, int xLoc, int zLoc, int yRotation, float xScale, float yScale, float zScale) : renderer(renderer) {
//Base
	graph = new Graph(renderer);
	graph->xLoc = xLoc * xScale;
	graph->yLoc = 4 * yScale;
	graph->zLoc = zLoc * zScale;
	graph->yRotation = yRotation;
	graph->xScale = 2.0f * xScale;
	graph->yScale = 0.2f;
	graph->zScale = 2.0f * zScale;
	
//Leg 1
	Graph *leg1 = new Graph(renderer);
	leg1->xLoc = (1.5+ xLoc) * xScale;
	leg1->yLoc = 2 + 0 * yScale;
	leg1->zLoc = (1.5+ zLoc) * zScale;
	leg1->yRotation = yRotation;
	leg1->xScale = 0.5f * xScale;
	leg1->yScale = 2 * yScale;
	leg1->zScale = 0.5f * zScale;

//Leg 2
	Graph* leg2 = new Graph(renderer);
	leg2->xLoc = (-1.5+ xLoc) * xScale;
	leg2->yLoc = 2 + 0 * yScale;
	leg2->zLoc = (1.5+ zLoc) * zScale;
	leg2->yRotation = yRotation;
	leg2->xScale = 0.5 * xScale;
	leg2->yScale = 2 * yScale;
	leg2->zScale = 0.5 * zScale;

//Leg 3
	Graph* leg3 = new Graph(renderer);
	leg3->xLoc = (-1.5+ xLoc) * xScale;
	leg3->yLoc = 2 + 0 * yScale;
	leg3->zLoc = (-1.5+ zLoc) * zScale;
	leg3->yRotation = yRotation;
	leg3->xScale = 0.5 * xScale;
	leg3->yScale = 2 * yScale;
	leg3->zScale = 0.5 * zScale;

//Leg 4
	Graph* leg4 = new Graph(renderer);
	leg4->xLoc = (1.5+ xLoc) * xScale;
	leg4->yLoc = 2 + 0 * yScale;
	leg4->zLoc = (-1.5+ zLoc) * zScale;
	leg4->yRotation = yRotation;
	leg4->xScale = 0.5 * xScale;
	leg4->yScale = 2 * yScale;
	leg4->zScale = 0.5 * zScale;

//Back
	Graph* back = new Graph(renderer);
	back->xLoc = xLoc * xScale;
	back->yLoc = 6 * yScale;
	back->zLoc = (1.8 + zLoc) * zScale;
	back->yRotation = yRotation;
	back->xScale = 2.0f * xScale;
	back->yScale = 2 * yScale;
	back->zScale = 0.2f * zScale;

	graph->graft(leg1);
	graph->graft(leg2);
	graph->graft(leg3);
	graph->graft(leg4);
	graph->graft(back);
}

Chair::~Chair() {
	delete graph;
}

void Chair::draw() {
	graph->visit();
}