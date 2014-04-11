/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The class for rendering light. 
*/

#include "Light.h"

Light::Light(Cube *cube, Shader *shader) : cube(cube), shader(shader) {
	position = lightNS::DEF_POSITION;

//Extract variables from the shader program
	light = glGetUniformLocation(shader->shaderProgram, lightNS::SHD_LIGHT);
}

Light::~Light() { }

void Light::draw() {
	glm::vec4 shaderVec = glm::vec4(position.x, position.y, position.z, 1.0f);
	glUniform4fv(light, 1, &shaderVec[0]);

	if (lightNS::DEF_SRC_CUBE_SHOW) {
		cube->setTranslation(position);
		cube->setColor(ALL, lightNS::DEF_SRC_CUBE_COLOR);
		cube->draw();
	}
}

glm::vec3 Light::getPosition() const {
	return position;
}

float Light::getPosition(Axis axis) const {
	if (axis == X || axis == Y || axis == Z) {
		return position[axis];
	}

	return -1.0f;
}

int Light::getSourceCubeColor() const {
	return cubeColor;
}

bool Light::getSourceCubeVisible() const {
	return sourceVisible;
}

void Light::setPosition(const glm::vec3 position) {
	this->position = position;
	draw();
}

void Light::setPosition(const Axis axis, const float position) {
	if (axis == X || axis == Y || axis == Z) {
		this->position[axis] = position;
		draw();
	}
}

void Light::setSourceCubeColor(const int color) {
	cubeColor = color;
}

void Light::setSourceCubeVisible(const bool visible) {
	sourceVisible = visible;
}