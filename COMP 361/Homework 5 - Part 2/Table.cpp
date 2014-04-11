/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Table object on display. 
*/

#include "Table.h"

Table::Table(Cube *cube) : CubeObject(cube) {
	unitLength = tableNS::UNIT_LENGTH;
	unitWidth = tableNS::UNIT_WIDTH;
}

Table::~Table() { }

void Table::init() {
	float offset = ceilf(tableNS::TOP_HEIGHT) - tableNS::TOP_HEIGHT;

//Base
	graph = new Graph(cube);
	graph->cube->setColor(ALL, CYAN);
	graph->location.x = translate.x * scale.x;
	graph->location.y = (tableNS::LEG_HEIGHT + offset) * scale.y;
	graph->location.z = translate.z * scale.z;
	graph->rotation.y = rotation.y;
	graph->scale.x = tableNS::TOP_LENGTH * scale.x;
	graph->scale.y = tableNS::TOP_HEIGHT * scale.y;
	graph->scale.z = tableNS::TOP_WIDTH * scale.z;

//Leg 1
	Graph *leg1 = new Graph(cube);
	leg1->cube->setColor(ALL, CYAN);
	leg1->location.x = (tableNS::LEG_RADIUS + translate.x) * scale.x;
	leg1->location.y = 1 * scale.y;
	leg1->location.z = (tableNS::LEG_RADIUS + translate.z) * scale.z;
	leg1->rotation.y = rotation.y;
	leg1->scale.x = tableNS::LEG_LENGTH * scale.x;
	leg1->scale.y = tableNS::LEG_HEIGHT * scale.y;
	leg1->scale.z = tableNS::LEG_WIDTH * scale.z;

//Leg 2
	Graph *leg2 = new Graph(cube);
	leg2->cube->setColor(ALL, CYAN);
	leg2->location.x = (-tableNS::LEG_RADIUS + translate.x) * scale.x;
	leg2->location.y = 1 * scale.y;
	leg2->location.z = (tableNS::LEG_RADIUS + translate.z) * scale.z;
	leg2->rotation.y = rotation.y;
	leg2->scale.x = tableNS::LEG_LENGTH * scale.x;
	leg2->scale.y = tableNS::LEG_HEIGHT * scale.y;
	leg2->scale.z = tableNS::LEG_WIDTH * scale.z;

//Leg 3
	Graph *leg3 = new Graph(cube);
	leg3->cube->setColor(ALL, CYAN);
	leg3->location.x = (-tableNS::LEG_RADIUS + translate.x) * scale.x;
	leg3->location.y = 1 * scale.y;
	leg3->location.z = (-tableNS::LEG_RADIUS + translate.z) * scale.z;
	leg3->rotation.y = rotation.y;
	leg3->scale.x = tableNS::LEG_LENGTH * scale.x;
	leg3->scale.y = tableNS::LEG_HEIGHT * scale.y;
	leg3->scale.z = tableNS::LEG_WIDTH * scale.z;

//Leg 4
	Graph *leg4 = new Graph(cube);
	leg4->cube->setColor(ALL, CYAN);
	leg4->location.x = (tableNS::LEG_RADIUS + translate.x) * scale.x;
	leg4->location.y = 1 * scale.y;
	leg4->location.z = (-tableNS::LEG_RADIUS + translate.z) * scale.z;
	leg4->rotation.y = rotation.y;
	leg4->scale.x = tableNS::LEG_LENGTH * scale.x;
	leg4->scale.y = tableNS::LEG_HEIGHT * scale.y;
	leg4->scale.z = tableNS::LEG_WIDTH * scale.z;

	graph->graft(leg1);
	graph->graft(leg2);
	graph->graft(leg3);
	graph->graft(leg4);
}