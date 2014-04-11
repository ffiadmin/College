/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Table object on display. 
*/

#pragma once

#include "CubeObject.h"

namespace tableNS {
//Legs
	const float LEG_HEIGHT  = 2.5f;
	const float LEG_LENGTH  = 0.5f; // X direction
	const float LEG_RADIUS  = 4.5f;
	const float LEG_WIDTH   = 0.5f; // Z direction

//Top
	const float TOP_HEIGHT  = 0.2f;
	const float TOP_LENGTH  = 5.0f; // X direction
	const float TOP_WIDTH   = 5.0f; // Z direction

//Unit lengths
	const float UNIT_LENGTH = 5.0f; // X direction
	const float UNIT_WIDTH  = 5.0f; // Z direction
}

class Table : public CubeObject {
public : 
	Table(Cube *cube);
	~Table();

	void init();
};