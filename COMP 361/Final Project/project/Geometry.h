/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the class definition for the abstract base type, Geometry.
*/
#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "../glm/glm.hpp"
#include <QGLWidget>
#include <stdlib.h>
#define BUFFER_OFFSET(bytes) ((GLvoid*) (bytes))
#include "../glm/gtc/matrix_transform.hpp"
#include "Utility.h"
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include "Ray.h"
#include "stubs.h"

class Geometry
{
public:
	Geometry(void);
	~Geometry(void);
	virtual void initialize(unsigned int shaderProgram, unsigned int u_modelMatrix) = 0;
	virtual void draw(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate) = 0;
	virtual void draw(glm::mat4 Matrix, glm::vec3 color) = 0;
	virtual void setColor(glm::vec3 color) = 0;
	glm::mat4 modelMatrix;
	virtual bool collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity) = 0;
	virtual void subDivide(int iters = 1);

protected:
	
    glm::mat4 localMatrix;

	glm::vec4 avg(glm::vec4 &p1, glm::vec4 &p2);
};

