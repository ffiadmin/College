/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the implementation of a node in a scene graph.
*/

#include "Node.h"


Node::Node()
{
	transform = glm::mat4(1.0f);
	geometry = NULL;
	nextObject = NULL;
	this->color = glm::vec3(0, 0, 1);
	height = 0;
	y = 0;	
}

Node::Node(glm::mat4 matrix, Geometry* model)
{
	transform = matrix;
	geometry = model;
	nextObject = NULL;
	this->x = x;
	this->z = z;
	this->color = glm::vec3(0, 0, 1); //Default Blue
	height = 1;
	reRot = 0;
	sZ = 1;
	sX = 1;
	sY = 1;
	mX = 0;
	mZ = 0;
	liveTransform = glm::mat4(1.0f);
	liveTransform = glm::scale(liveTransform, glm::vec3(sX, sY, sZ));
	liveTransform = glm::rotate(liveTransform, reRot, glm::vec3(0, 1, 0));
	liveTransform = glm::translate(liveTransform, glm::vec3(mX, 0 , mZ));
}


Node::~Node(void)
{
}

void Node::visitChildren(glm::mat4 xform)
{
    if (geometry != NULL)
	{
		geometry->draw(xform * transform * liveTransform, color);
	}
	for (int i=0; i<children.size(); ++i)
	{
		children.at(i)->visitChildren(xform * transform * liveTransform);
	}
	if (nextObject != NULL)
	{
		nextObject->visitChildren(xform * transform * liveTransform);
	}
}

void Node::setColor(glm::vec3 color)
{
	this->color = color;
}

void Node::addObject(Node* newModel)
{
	if (nextObject == NULL)
	{
		nextObject = newModel;
		nextObject->setY(getY());
	}
	else
	{
		nextObject->addObject(newModel);
	}
}

float Node::getY()
{
	return y + height;
}

void Node::setY(float yVal)
{
	 y = yVal;
	 transform = glm::translate(transform, glm::vec3(0, y, 0)); 
}

void Node::updateTransform()
{
	liveTransform = glm::mat4(1.0f);
	liveTransform = glm::scale(liveTransform, glm::vec3(sX, sY, sZ));
	liveTransform = glm::rotate(liveTransform, reRot, glm::vec3(0, 1, 0));
	liveTransform = glm::translate(liveTransform, glm::vec3(mX, 0 , mZ));
}