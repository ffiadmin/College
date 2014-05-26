/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the function definitions for the Table class.
*/
#include "Chair.h"
#include "HECube.h"

Chair::Chair(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate)
{
	localMatrix = toMat(Scale, Rotate, RotAngle, Translate);
	setCube(new HECube(vec3(1, 1, 1), vec3(0, 1, 0), 0.0f, vec3(0, 0, 0)));
	glm::mat4 xform;
	xform = toMat(Scale, glm::vec3(0,1,0), RotAngle, Translate);
	Node* chair = new Node(xform, NULL);

	xform = toMat(glm::vec3(1, 0.1, 1), glm::vec3(0,1,0), 0.0f, glm::vec3(0, 1, 0));//Top
	chair->children.push_back(new Node(xform, cube));

	xform = toMat(glm::vec3(0.1, 1, 0.1), glm::vec3(0,1,0), 0.0f, glm::vec3(0.45, 0, 0.45));//Legs
	chair->children.push_back(new Node(xform, cube));
	xform = toMat(glm::vec3(0.1, 1, 0.1), glm::vec3(0,1,0), 0.0f, glm::vec3(-0.45, 0, 0.45));
	chair->children.push_back(new Node(xform, cube));
	xform = toMat(glm::vec3(0.1, 1, 0.1), glm::vec3(0,1,0), 0.0f, glm::vec3(0.45, 0, -0.45));
	chair->children.push_back(new Node(xform, cube));
	xform = toMat(glm::vec3(0.1, 1, 0.1), glm::vec3(0,1,0), 0.0f, glm::vec3(-0.45, 0, -0.45));
	chair->children.push_back(new Node(xform, cube));
	xform = toMat(glm::vec3(1, 1, 0.1), glm::vec3(0,1,0), 0.0f, glm::vec3(0, 1, -0.45));//Back
	chair->children.push_back(new Node(xform, cube));

	subGeometry = chair;
}
Chair::Chair()
{
    localMatrix = glm::mat4(1.0f);
	
	localMatrix = glm::scale(localMatrix, glm::vec3(1, 1, 1));
	localMatrix = glm::rotate(localMatrix, 0.0f, glm::vec3(1, 1, 1));
	localMatrix = glm::translate(localMatrix, glm::vec3(0, 0, 0));
}


Chair::~Chair(void)
{
}

void Chair::initialize(unsigned int shaderProgram, unsigned int modelMatrix)
{
	cube->initialize(shaderProgram, modelMatrix);
}

void Chair::draw(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate)
{
	//Start with identity matrix
	modelMatrix = toMat(Scale, Rotate, RotAngle, Translate);

	modelMatrix =  localMatrix * modelMatrix;

	for(int i=0; i<subGeometry->children.size(); ++i)
	{
		subGeometry->children.at(i)->visitChildren(modelMatrix);
	}


}
void Chair::draw(glm::mat4 Matrix, glm::vec3 color)
{

	setColor(color);
	for(int i=0; i<subGeometry->children.size(); ++i)
	{
		subGeometry->children.at(i)->visitChildren(Matrix * localMatrix);
	}
}

void Chair::setCube(Geometry* _cube)
{
	cube = _cube;
}
void Chair::setColor(glm::vec3 color)
{
	for(int i=0; i<subGeometry->children.size(); ++i)
	{
		subGeometry->children.at(i)->setColor(color);
	}
}

bool Chair::collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity)
{
	return false;
}