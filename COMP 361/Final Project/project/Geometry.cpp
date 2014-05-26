/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the implementation of the Geometry base class.
*/

#include "Geometry.h"


Geometry::Geometry(void)
{
}


Geometry::~Geometry(void)
{
}

void Geometry::subDivide(int iters) {
	// Only for Half Edges, dude!
}

glm::vec4 Geometry::avg(glm::vec4 &v1, glm::vec4 &v2) {
	glm::vec4 out;
	out.x = (v1.x + v2.x) / 2.0f;
	out.y = (v1.y + v2.y) / 2.0f;
	out.z = (v1.z + v2.z) / 2.0f;
	out.w = 1.0f;

	return out;
}