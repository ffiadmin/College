/* 
 Author: Oliver Spryn and Course Textbook
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This is the basic data type for the data structure for creating a scene graph.
*/

#pragma once

#include "Cube.h"

#include <vector>

using std::vector;

struct Graph {
public : 
	Graph(Cube *cube);
	~Graph();

	void destroyChildren();
	void graft(Graph *graph);
	void visit();

	Cube *cube;
	vector<Graph*> children;

	glm::vec3 location;
	glm::vec3 rotation;
	glm::vec3 scale;

private : 
	bool hasChildren;
};