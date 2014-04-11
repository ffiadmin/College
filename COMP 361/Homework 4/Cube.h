/* 
 Author: Oliver Spryn and Course Textbook
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This is a wrapper class for generating a Cube in OpenGL with basic functionality. 
*/

#pragma once

#include "Camera.h"
#include "Geometry.h"
#include "Shader.h"

enum Side { SOUTH, EAST, DOWN, UP, NORTH, WEST, ALL };

namespace cubeNS {
//Cube defaults
	const int       DEF_COLORS[6] = {
		RED, GREEN, BLUE, MAGENTA, YELLOW, CYAN
	};

//Cube data
	const int       TOTAL         = 36;
	const glm::vec4 NORMALS[36]   = {
	//SOUTH +z
		glm::vec4(0, 0, 1, 0),
		glm::vec4(0, 0, 1, 0),
		glm::vec4(0, 0, 1, 0),
		glm::vec4(0, 0, 1, 0),
		glm::vec4(0, 0, 1, 0),
		glm::vec4(0, 0, 1, 0),

	//EAST +x
		glm::vec4(1, 0, 0, 0),
		glm::vec4(1, 0, 0, 0),
		glm::vec4(1, 0, 0, 0),
		glm::vec4(1, 0, 0, 0),
		glm::vec4(1, 0, 0, 0),
		glm::vec4(1, 0, 0, 0),

	//DOWN -y
		glm::vec4(0, -1, 0, 0),
		glm::vec4(0, -1, 0, 0),
		glm::vec4(0, -1, 0, 0),
		glm::vec4(0, -1, 0, 0),
		glm::vec4(0, -1, 0, 0),
		glm::vec4(0, -1, 0, 0),

	//UP +y
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 1, 0, 0),
	
	//NORTH -z
		glm::vec4(0, 0, -1, 0),
		glm::vec4(0, 0, -1, 0),
		glm::vec4(0, 0, -1, 0),
		glm::vec4(0, 0, -1, 0),
		glm::vec4(0, 0, -1, 0),
		glm::vec4(0, 0, -1, 0),

	//WEST -x
		glm::vec4(-1, 0, 0, 0),
		glm::vec4(-1, 0, 0, 0),
		glm::vec4(-1, 0, 0, 0),
		glm::vec4(-1, 0, 0, 0),
		glm::vec4(-1, 0, 0, 0),
		glm::vec4(-1, 0, 0, 0)
	};

	const glm::vec4 VERTICIES[8]  = {
		glm::vec4( -0.5, -0.5,  0.5, 0.5 ),
		glm::vec4( -0.5,  0.5,  0.5, 0.5 ),
		glm::vec4(  0.5,  0.5,  0.5, 0.5 ),
		glm::vec4(  0.5, -0.5,  0.5, 0.5 ),
		glm::vec4( -0.5, -0.5, -0.5, 0.5 ),
		glm::vec4( -0.5,  0.5, -0.5, 0.5 ),
		glm::vec4(  0.5,  0.5, -0.5, 0.5 ),
		glm::vec4(  0.5, -0.5, -0.5, 0.5 )
	};
}

class Cube : public Geometry {
public : 
	Cube(Shader *shader);
	~Cube();

//Getters and setters
	glm::vec3 getColor(Side side) const;
	void setColor(const Side side, const Colors color);

//Public interface for cube manipulation and display
	virtual void draw();

private : 
//Cube data
	int cSides[6];
	glm::vec3 colors[cubeNS::TOTAL];
	glm::vec4 normals[cubeNS::TOTAL];
	glm::vec4 points[cubeNS::TOTAL];

	virtual void buildGeometry();
	void quad(int &index, int color, int a, int b, int c, int d);
	void reset(bool bufferReady);
};