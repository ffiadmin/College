/* 
 Author: Oliver Spryn and Course Textbook
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This is a wrapper class for generating a Cube in OpenGL with basic functionality. 
*/

#include "Cube.h"

Cube::Cube(Shader *shader) : Geometry(shader) {
	for(int i = 0; i < cubeNS::TOTAL; ++i) {
		normals[i] = cubeNS::NORMALS[i];
	}

	reset(false);
	buildGeometry();
	buildBuffer(cubeNS::TOTAL, colors, normals, points);
}

Cube::~Cube() { }

void Cube::buildGeometry() {
	int index = 0;

	quad(index, cSides[0], 1, 0, 3, 2); //SOUTH +z
	quad(index, cSides[1], 2, 3, 7, 6); //EAST +x
	quad(index, cSides[2], 3, 0, 4, 7); //DOWN -y
	quad(index, cSides[3], 6, 5, 1, 2); //UP +y
	quad(index, cSides[4], 4, 5, 6, 7); //NORTH -z
	quad(index, cSides[5], 5, 4, 0, 1); //WEST -x
}

void Cube::draw() {
	Geometry::masterDraw();

	glDrawArrays(GL_TRIANGLES, 0, cubeNS::TOTAL);
	reset(true);
}

glm::vec3 Cube::getColor(Side side) const {
	if (side == SOUTH || side == EAST || side == DOWN || side == UP || side == NORTH || side == WEST || side == ALL) {
		return colors[side];
	}

	return glm::vec3(-1.0f, -1.0f, -1.0f);
}

void Cube::quad(int &index, int color, int a, int b, int c, int d) {
	colors[index] = geometryNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[a];
	index++;

	colors[index] = geometryNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[b];
	index++;

	colors[index] = geometryNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[c];
	index++;

	colors[index] = geometryNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[a];
	index++;

	colors[index] = geometryNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[c];
	index++;

	colors[index] = geometryNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[d];
	index++;
}

void Cube::reset(bool bufferReady) {
	Geometry::masterReset(bufferReady);

	cSides[0] = cubeNS::DEF_COLORS[0];
	cSides[1] = cubeNS::DEF_COLORS[1];
	cSides[2] = cubeNS::DEF_COLORS[2];
	cSides[3] = cubeNS::DEF_COLORS[3];
	cSides[4] = cubeNS::DEF_COLORS[4];
	cSides[5] = cubeNS::DEF_COLORS[5];

	if (bufferReady) {
		size_t szColors = cubeNS::TOTAL * sizeof(glm::vec3);
		size_t szVertices = cubeNS::TOTAL * sizeof(glm::vec4);

		//glBufferSubData(GL_ARRAY_BUFFER, szVertices, szColors, colors);
	}
}

void Cube::setColor(const Side side, const Colors color) {
	if (side != ALL) {
		cSides[side] = color;
	} else {
		cSides[0] = color;
		cSides[1] = color;
		cSides[2] = color;
		cSides[3] = color;
		cSides[4] = color;
		cSides[5] = color;
	}

//Update the buffer
	size_t szColors = cubeNS::TOTAL * sizeof(glm::vec3);
	size_t szVertices = cubeNS::TOTAL * sizeof(glm::vec4);

	buildGeometry();
	glBufferSubData(GL_ARRAY_BUFFER, szVertices, szColors, colors);
}