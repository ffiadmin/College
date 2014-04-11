/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for creating and modifying a Box object on display. 
*/

#pragma once

#include "CubeObject.h"

namespace boxNS {
//Unit lengths
	const float UNIT_LENGTH = 1.0f; // X direction
	const float UNIT_WIDTH  = 1.0f; // Z direction
}

class Box : public CubeObject {
public : 
	Box(Cube *cube);
	~Box();

	void init();
};