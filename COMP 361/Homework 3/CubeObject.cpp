/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The base class for all objects which are rendered as groups on screen. 
*/

#include "CubeObject.h"

CubeObject::CubeObject(Cube *cube) : cube(cube) { }

CubeObject::~CubeObject() {
	delete graph;
}

void CubeObject::draw() {
	graph->visit();
}

glm::vec3 CubeObject::getRotation() const {
	return rotation;
}

float CubeObject::getRotation(Axis axis) const {
	if (axis == X || axis == Y || axis == Z) {
		return rotation[axis];
	}

	return -1.0f;
}

glm::vec3 CubeObject::getScale() const {
	return scale;
}

float CubeObject::getScale(Axis axis) const {
	if (axis == X || axis == Y || axis == Z) {
		return scale[axis];
	}

	return -1.0f;
}

glm::vec3 CubeObject::getTranslation() const {
	return translate;
}

float CubeObject::getTranslation(Axis axis) const {
	if (axis == X || axis == Y || axis == Z) {
		return scale[axis];
	}

	return -1.0f;
}

float CubeObject::getUnitLength() const {
	return unitLength;
}

float CubeObject::getUnitWidth() const {
	return unitWidth;
}

void CubeObject::setRotation(const glm::vec3 rotation) {
	this->rotation = rotation;
}

void CubeObject::setRotation(const Axis axis, const float rotation) {
	if ((axis == X || axis == Y || axis == Z) && rotation >= 0.0f) {
		this->rotation[axis] = rotation;
	}
}

void CubeObject::setScale(const glm::vec3 factor) {
	scale = factor;
}

void CubeObject::setScale(const Axis axis, const float factor) {
	if ((axis == X || axis == Y || axis == Z) && factor >= 0.0f) {
		scale[axis] = factor;
	}
}

void CubeObject::setTranslation(const glm::vec3 translation) {
	translate = translation;
}

void CubeObject::setTranslation(const Axis axis, const float translation) {
	if ((axis == X || axis == Y || axis == Z) && translation >= 0.0f) {
		translate[axis] = translation;
	}
}