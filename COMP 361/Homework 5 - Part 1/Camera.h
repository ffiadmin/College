/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The camera class for viewing objects. 
*/

#pragma once
#define GLEW_STATIC

#include "Common.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"

namespace cameraNS {
//Camera configuration
	const glm::vec3 EYE           = glm::vec3(15.0f, 15.0f, 15.0f);
	const float     FAR_CLIPPING  = 100.0f;
	const float     FIELD_OF_VIEW = 90.0f;
	const float     NEAR_CLIPPING = 0.1f;

//Shader variables
	const char      SHD_CAM_MTX[] = "u_camMatrix";
};

class Camera {
public : 
	Camera(Shader *shader);
	~Camera();

//Getter and setters
	glm::vec3 getEye() const;
	float getEye(Axis axis) const;
	void setEye(const glm::vec3 position);
	void setEye(const Axis axis, const float position);

	void placeCamera(const int windowWidth, const int windowHeight);

private : 
	Shader *shader;

//Location matricies
	unsigned int camMatrix;

//Camera positioning
	glm::vec3 eye;
	int windowHeight;
	int windowWidth;
};