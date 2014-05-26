/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the class definition for a node in a scene graph.
*/

#pragma once
#include "glew.h"
#include "../glm/glm.hpp"
#include <QGLWidget>
#include <stdlib.h>
#include "Geometry.h"
#include <vector>
using std::vector;

#include "../glm/gtc/matrix_transform.hpp"
class Node
{
public:
	Node();
	Node(glm::mat4 matrix, Geometry* model);
	~Node(void);
public:
    glm::mat4 transform;
	glm::mat4 liveTransform;
    Geometry* geometry;
    vector<Node*> children;
	Node* nextObject;
    void visitChildren(glm::mat4 xform);
	float x, y, z;
	float height;
	float sX, sZ, sY, reRot;
	int mX, mZ; 
	glm::vec3 color;
	void setColor(glm::vec3 color);
	void addObject(Node* newModel);
	void setY(float yVal);
	void updateTransform();
	float getY();
};

