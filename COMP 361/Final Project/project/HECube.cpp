#include "HECube.h"


HECube::HECube(void)
{
}

HECube::HECube(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate) : HEExtrusion(Scale, Rotate, RotAngle, Translate)
{
	VertLine base;
	base.addVertex(vec4(-0.5, 0, -0.5, 0));
	base.addVertex(vec4(-0.5, 0, 0.5, 0));
	base.addVertex(vec4(0.5, 0, 0.5, 0));
	base.addVertex(vec4(0.5, 0, -0.5, 0));

	extrude(base);
}

void HECube::initialize(unsigned int shaderProgram, unsigned int u_modelMatrix)
{
	HalfEdge::initialize(shaderProgram, u_modelMatrix);
}


HECube::~HECube(void)
{
}
bool HECube::collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity)
{
	double t = Test_RayCubeIntersect(vec3(ray.origin.x, ray.origin.y, ray.origin.z), 
		vec3(ray.direction.x, ray.direction.y, ray.direction.z), modelMatrix);
	if(t>0)
	{
		color = vec3(0, 0, 1);
		return true;
	}
	return false; //change this
}