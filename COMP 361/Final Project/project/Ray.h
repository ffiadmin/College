#pragma once
#include "glm\glm.hpp"
using glm::vec4;

class Ray
{
public:
	Ray(void);
	~Ray(void);

	vec4 origin;
	vec4 direction;
};

