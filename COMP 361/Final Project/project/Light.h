#pragma once
#define GLEW_STATIC
#include "Geometry.h"
#include "glew.h"
#include "../glm/glm.hpp"
#include <stdlib.h>
#include "../glm/gtc/matrix_transform.hpp"
class Light
{
public:
	Light(void);
	~Light(void);

	void setPosition(float x, float y, float z);
	void addPosition(float x, float y, float z);
	void initialize(unsigned int u_lightPos);
	glm::vec4 position;
	unsigned int u_lightPos;
	void draw();
	static Geometry* cube;
	static void setCube(Geometry* _cube);
};

