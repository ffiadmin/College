/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Chair object on display. 
*/

#pragma once

#include "CubeObject.h"

namespace chairNS {
//Back
	const float BACK_HEIGHT = 2.0f;

//Legs
	const float LEG_HEIGHT  = 2.0f;
	const float LEG_LENGTH  = 0.25f; // X direction
	const float LEG_RADIUS  = 1.75f;
	const float LEG_WIDTH   = 0.25f; // Z direction

//Top
	const float TOP_HEIGHT  = 0.2f;
	const float TOP_LENGTH  = 2.0f;  // X direction
	const float TOP_WIDTH   = 2.0f;  // Z direction

//Unit lengths
	const float UNIT_LENGTH = 2.0f;  // X direction
	const float UNIT_WIDTH  = 2.0f;  // Z direction
}

class Chair : public CubeObject {
public : 
	Chair(Cube *cube);
	~Chair();

	void init();
};