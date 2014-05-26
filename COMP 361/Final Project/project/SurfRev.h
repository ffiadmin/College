#pragma once
#include "mesh.h"
class SurfRev :
	public Mesh
{
public:
	SurfRev(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate);
	~SurfRev(void);
	void import(ifstream& reader);
	vector<Face> rotate(Face polygon);
	bool collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity);
private:
	int slices;
};

