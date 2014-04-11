/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The camera class for viewing objects. 
*/

#include "Camera.h"

Camera::Camera(Shader *shader) : eye(cameraNS::EYE), shader(shader) {
//Extract variables from the shader program
	camMatrix = glGetUniformLocation(shader->shaderProgram, cameraNS::SHD_CAM_MTX);
}

Camera::~Camera() { }

glm::vec3 Camera::getEye() const {
	return eye;
}

float Camera::getEye(Axis axis) const {
	if (axis == X || axis == Y || axis == Z) {
		return eye[axis];
	}

	return -1.0f;
}

void Camera::placeCamera(const int windowWidth, const int windowHeight) {
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;

//Define the boundaries of the viewport
	glViewport(0, 0, windowWidth, windowHeight);

//Define the camera projection matrix
	glm::mat4 projection = glm::perspective(cameraNS::FIELD_OF_VIEW, static_cast<float>(windowWidth) / static_cast<float>(windowHeight), cameraNS::NEAR_CLIPPING, cameraNS::FAR_CLIPPING);
	glm::mat4 camera = glm::lookAt(eye, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	
//Set the shader variables
	glUniformMatrix4fv(camMatrix, 1, GL_FALSE, &camera[0][0]);
	glUniformMatrix4fv(shader->projectionMatrix, 1, GL_FALSE, &projection[0][0]);
}

void Camera::setEye(const glm::vec3 position) {
	eye = position;
	placeCamera(windowWidth, windowHeight);
}

void Camera::setEye(const Axis axis, const float position) {
	if (axis == X || axis == Y || axis == Z) {
		eye[axis] = position;
		placeCamera(windowWidth, windowHeight);
	}
}