/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the function definitions for the Table class.
*/
#include "Table.h"
#include "HECube.h"


Table::Table(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate)
{
	setCube(new HECube(vec3(1, 1, 1), vec3(0, 1, 0), 0.0f, vec3(0, 0, 0)));
	localMatrix = glm::mat4(1.0f);
	localMatrix = glm::scale(localMatrix, Scale);
	localMatrix = glm::rotate(localMatrix, RotAngle, Rotate);
	localMatrix = glm::translate(localMatrix, Translate);

	glm::mat4 xform;
	xform = toMat(Scale, glm::vec3(0,1,0), RotAngle, Translate);
	Node* table = new Node(xform, NULL);

	xform = toMat(glm::vec3(1, 0.1, 1), glm::vec3(0,1,0), 0.0f, glm::vec3(0, 1, 0));//Top
	table->children.push_back(new Node(xform, cube));

	xform = toMat(glm::vec3(0.1, 1, 0.1), glm::vec3(0,1,0), 0.0f, glm::vec3(0.45, 0, 0.45));//Legs
	table->children.push_back(new Node(xform, cube));
	xform = toMat(glm::vec3(0.1, 1, 0.1), glm::vec3(0,1,0), 0.0f, glm::vec3(-0.45, 0, 0.45));
	table->children.push_back(new Node(xform, cube));
	xform = toMat(glm::vec3(0.1, 1, 0.1), glm::vec3(0,1,0), 0.0f, glm::vec3(0.45, 0, -0.45));
	table->children.push_back(new Node(xform, cube));
	xform = toMat(glm::vec3(0.1, 1, 0.1), glm::vec3(0,1,0), 0.0f, glm::vec3(-0.45, 0, -0.45));
	table->children.push_back(new Node(xform, cube));
	subGeometry = table;
}
Table::Table()
{
    localMatrix = glm::mat4(1.0f);
	
	localMatrix = glm::scale(localMatrix, glm::vec3(1, 1, 1));
	localMatrix = glm::rotate(localMatrix, 0.0f, glm::vec3(1, 1, 1));
	localMatrix = glm::translate(localMatrix, glm::vec3(0, 0, 0));
}


Table::~Table(void)
{
}

void Table::initialize(unsigned int shaderProgram, unsigned int modelMatrix)
{
	cube->initialize(shaderProgram, modelMatrix);
}

void Table::draw(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate)
{
	//Start with identity matrix
	modelMatrix = glm::mat4(1.0f);
	
	modelMatrix = glm::scale(modelMatrix, Scale);
	modelMatrix = glm::rotate(modelMatrix, RotAngle, Rotate);
	modelMatrix = glm::translate(modelMatrix, Translate);

	modelMatrix =  localMatrix * modelMatrix;

	for(int i=0; i<subGeometry->children.size(); ++i)
	{
		subGeometry->children.at(i)->visitChildren(modelMatrix);
	}


}
void Table::draw(glm::mat4 Matrix, glm::vec3 color)
{
	setColor(color);
	for(int i=0; i<subGeometry->children.size(); ++i)
	{
		subGeometry->children.at(i)->visitChildren(Matrix * localMatrix);
	}
}

void Table::setCube(Geometry* _cube)
{
	cube = _cube;
}
void Table::setColor(glm::vec3 color)
{
	for(int i=0; i<subGeometry->children.size(); ++i)
	{
		subGeometry->children.at(i)->setColor(color);
	}
}

bool Table::collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity)
{
	return false;
}