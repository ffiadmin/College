/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Chair object on display. 
*/

#include "Chair.h"

Chair::Chair(Cube *cube) : CubeObject(cube) {
	unitLength = chairNS::UNIT_LENGTH;
	unitWidth = chairNS::UNIT_WIDTH;
}

Chair::~Chair() { }

void Chair::init() {
	float offset = ceilf(chairNS::TOP_HEIGHT) - chairNS::TOP_HEIGHT;

//Base
	graph = new Graph(cube);
	graph->location.x = translate.x * scale.x;
	graph->location.y = (chairNS::LEG_HEIGHT + offset) * scale.y;
	graph->location.z = translate.z * scale.z;
	graph->rotation.y = rotation.y;
	graph->scale.x = chairNS::TOP_LENGTH * scale.x;
	graph->scale.y = chairNS::TOP_HEIGHT * scale.y;
	graph->scale.z = chairNS::TOP_WIDTH * scale.z;
	
//Leg 1
	Graph *leg1 = new Graph(cube);
	leg1->location.x = (chairNS::LEG_RADIUS + translate.x) * scale.x;
	leg1->location.y = 1 * scale.y;
	leg1->location.z = (chairNS::LEG_RADIUS + translate.z) * scale.z;
	leg1->rotation.y = rotation.y;
	leg1->scale.x = chairNS::LEG_LENGTH * scale.x;
	leg1->scale.y = chairNS::LEG_HEIGHT * scale.y;
	leg1->scale.z = chairNS::LEG_WIDTH * scale.z;

//Leg 2
	Graph *leg2 = new Graph(cube);
	leg2->location.x = (-chairNS::LEG_RADIUS + translate.x) * scale.x;
	leg2->location.y = 1 * scale.y;
	leg2->location.z = (chairNS::LEG_RADIUS + translate.z) * scale.z;
	leg2->rotation.y = rotation.y;
	leg2->scale.x = chairNS::LEG_LENGTH * scale.x;
	leg2->scale.y = chairNS::LEG_HEIGHT * scale.y;
	leg2->scale.z = chairNS::LEG_WIDTH * scale.z;

//Leg 3
	Graph *leg3 = new Graph(cube);
	leg3->location.x = (-chairNS::LEG_RADIUS + translate.x) * scale.x;
	leg3->location.y = 1 * scale.y;
	leg3->location.z = (-chairNS::LEG_RADIUS + translate.z) * scale.z;
	leg3->rotation.y = rotation.y;
	leg3->scale.x = chairNS::LEG_LENGTH * scale.x;
	leg3->scale.y = chairNS::LEG_HEIGHT * scale.y;
	leg3->scale.z = chairNS::LEG_WIDTH * scale.z;

//Leg 4
	Graph *leg4 = new Graph(cube);
	leg4->location.x = (chairNS::LEG_RADIUS + translate.x) * scale.x;
	leg4->location.y = 1 * scale.y;
	leg4->location.z = (-chairNS::LEG_RADIUS + translate.z) * scale.z;
	leg4->rotation.y = rotation.y;
	leg4->scale.x = chairNS::LEG_LENGTH * scale.x;
	leg4->scale.y = chairNS::LEG_HEIGHT * scale.y;
	leg4->scale.z = chairNS::LEG_WIDTH * scale.z;

//Back
	Graph *back = new Graph(cube);
	back->location.x = translate.x * scale.x;
	back->location.y = (chairNS::LEG_HEIGHT + chairNS::BACK_HEIGHT + offset) * scale.y;
	back->location.z = (chairNS::TOP_WIDTH - chairNS::LEG_WIDTH + translate.z) * scale.z;
	back->rotation.y = rotation.y;
	back->scale.x = chairNS::TOP_LENGTH * scale.x;
	back->scale.y = chairNS::BACK_HEIGHT * scale.y;
	back->scale.z = chairNS::LEG_WIDTH * scale.z;

	graph->graft(leg1);
	graph->graft(leg2);
	graph->graft(leg3);
	graph->graft(leg4);
	graph->graft(back);
}