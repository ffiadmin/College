#pragma once
#include "heextrusion.h"
using glm::vec3;
using glm::vec4;
class HECube :
	public HEExtrusion
{
public:
	HECube(void);
	HECube(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate);
	~HECube(void);
	void initialize(unsigned int shaderProgram, unsigned int u_modelMatrix);
	bool collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity);
};

