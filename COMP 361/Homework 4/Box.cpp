/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Box object on display. 
*/

#include "Box.h"

Box::Box(Cube *cube) : CubeObject(cube) {
	unitLength = boxNS::UNIT_LENGTH;
	unitWidth = boxNS::UNIT_WIDTH;
}

Box::~Box() { }

void Box::init() {
	graph = new Graph(cube);
	graph->location.x = translate.x * scale.x;
	graph->location.y = scale.y;
	graph->location.z = translate.z * scale.z;
	graph->rotation.y = rotation.y;
	graph->scale.x = scale.x;
	graph->scale.y = scale.y;
	graph->scale.z = scale.z;
}