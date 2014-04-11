/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The base class for all renderable objects. 
*/

#pragma once
#define _USE_MATH_DEFINES

#include "Cube.h"
#include "Graph.h"

#include <cmath>

class CubeObject {
public : 
	CubeObject(Cube *cube);
	~CubeObject();

//Provide access to each of the elements of the object
	Graph *graph;

//Getter and setters
	float getUnitLength() const;
	float getUnitWidth() const;

	glm::vec3 getRotation() const;
	float getRotation(const Axis axis) const;
	glm::vec3 getScale() const;
	float getScale(const Axis axis) const;
	glm::vec3 getTranslation() const;
	float getTranslation(const Axis axis) const;

	void setRotation(const glm::vec3 rotation);
	void setRotation(const Axis axis, const float rotation);
	void setScale(const glm::vec3 factor);
	void setScale(const Axis axis, const float factor);
	void setTranslation(const glm::vec3 translation);
	void setTranslation(const Axis axis, const float translation);

//Public interface for display
	void draw();
	virtual void init() = 0;

protected : 
	Cube *cube;

//Geometry manipulation
	glm::vec3 rotation;
	glm::vec3 scale;
	glm::vec3 translate;

//Dimensions
	float unitLength; // X direction
	float unitWidth;  // Z direction
};