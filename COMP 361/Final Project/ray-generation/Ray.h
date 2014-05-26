#pragma once
#include "glm\glm.hpp"
using namespace glm;

class Ray
{
public:
	Ray(void);
	~Ray(void);

	vec4 origin;
	vec4 direction;
};

