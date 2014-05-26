/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the class definition for a Cube, which inherits from Geometry.
*/
#pragma once
#include "Mesh.h"
class Cube :
	public Mesh
{
public:
	Cube();
	Cube(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate);
	~Cube(void);
	bool collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity);
private:
	float height;
};

