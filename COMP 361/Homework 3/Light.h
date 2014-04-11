/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The class for rendering light. 
*/

#pragma once
#define GLEW_STATIC

#include "Common.h"
#include "Cube.h"
#include "glew.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"

namespace lightNS {
//Defaults
	const glm::vec3 DEF_POSITION       = glm::vec3(0.0f, 10.0f, 0.0f);
	const glm::vec3 DEF_SRC_CUBE_COLOR = glm::vec3(1.0, 1.0, 1.0);
	const bool      DEF_SRC_CUBE_SHOW  = false;

//Shader variables
	const char      SHD_LIGHT[]        = "u_lightPos";
}

class Light {
public : 
	Light(Cube *cube, Shader *shader);
	~Light();

//Getters and setters
	glm::vec3 getPosition() const;
	float getPosition(Axis axis) const;
	int getSourceCubeColor() const;
	bool getSourceCubeVisible() const;

	void setPosition(const glm::vec3 position);
	void setPosition(const Axis axis, const float position);
	void setSourceCubeColor(const int color);
	void setSourceCubeVisible(const bool visible);

//Draw the light source and indicating cube
	void draw();

private : 
	Cube *cube;
	Shader *shader;

//Location matricies
	unsigned int light;

//Light settings
	int cubeColor;
	glm::vec3 position;
	bool sourceVisible;
};