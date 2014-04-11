/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: The class to hold and manipulate a mesh data structure
*/

#pragma once

#include "Common.h"
#include "Geometry.h"

#include <vector>

using std::vector;

class Mesh {
public : 
	Mesh(Colors color);
	~Mesh();

//Interface for adding data to the container
	void addTriangle(glm::vec3 one, glm::vec3 two, glm::vec3 three);
	void addTriangle(glm::vec4 one, glm::vec4 two, glm::vec4 three);
	void dump();

//Hold the data for each point
	glm::vec3 *colors;
	glm::vec4 *normals;
	glm::vec4 *points;
	vector<glm::vec4> pts;

	int total;

private : 
	Colors color;
};