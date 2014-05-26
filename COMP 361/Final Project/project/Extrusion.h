#pragma once
#include "Mesh.h"
class Extrusion :
	public Mesh
{
public:
	Extrusion(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate);
	~Extrusion(void);
	void import(ifstream& reader);
	vector<Face> extrude(Face face);
	bool collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity);
private:
	float height;
};

