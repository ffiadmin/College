/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: The class to create surface revolution geometry
*/

#include "Surfrev.h"

Surfrev::Surfrev(string configFile, Shader *shader) : Geometry(shader), mesh(WHITE) {
	Geometry::masterReset(false);
	reloadFile(configFile);
}

Surfrev::~Surfrev() { }

void Surfrev::buildGeometry() {
	glm::vec4 current, next, nnext;

//Calculate the rotation matrix based on the number of slices
	float degrees = 360.0f / slices;
	glm::mat4 rotNowMatrix = glm::mat4(1.0f);
	glm::mat4 rotNextMatrix = glm::mat4(1.0f);

//Create the vertices for each rotation slice
	for(int i = 0; i < slices; ++i) {
		rotNextMatrix = glm::rotate(rotNextMatrix, degrees, glm::vec3(0, 1, 0));

	//Rotate each point, except for the first
		for(int j = 0; j < total - 1; ++j) { // Don't do the last side
			current = vertices[j] * rotNowMatrix;

		//Top-half triangle
			next = vertices[j + 1] * rotNextMatrix;
			nnext = vertices[j + 1] * rotNowMatrix;

			mesh.addTriangle(current, next, nnext);

		//Bottom-half triangle
			next = vertices[j] * rotNextMatrix;
			nnext = vertices[j + 1] * rotNextMatrix;

			mesh.addTriangle(current, next, nnext);
		}

		rotNowMatrix = glm::rotate(rotNowMatrix, degrees, glm::vec3(0, 1, 0));
	}

//The very last case
	int last = vertices.size() - 1;
	rotNowMatrix = glm::rotate(rotNowMatrix, 360 - degrees, glm::vec3(0, 1, 0));
	rotNextMatrix = glm::mat4(1.0f);
	current = vertices[last] * rotNowMatrix;

//Top-half triangle
	next = vertices[0] * rotNextMatrix;
	nnext = vertices[0] * rotNowMatrix;

	mesh.addTriangle(current, next, nnext);
}

void Surfrev::draw() {
	Geometry::masterDraw();

	glDrawArrays(GL_TRIANGLES, 0, mesh.total);
}

void Surfrev::reloadFile(string configFile) throw(FileNotFound, InvalidObjectType) {
	ifstream fin(configFile);

	if (!fin.is_open()) {
		throw FileNotFound(configFile + " is missing and cannot be loaded.");
	}

//Determine if this is the correct file type
	string type;
	fin >> type;

	if (type != surfrevNS::INPUT_FILE_TYPE) {
		throw InvalidObjectType(type + " is not a valid object type from the input file. It should be " + surfrevNS::INPUT_FILE_TYPE + ".");
	}

//Determine the number of slices
	fin >> slices;

//Determine the number of vertices
	fin >> total;

//Gather each of the vertices
	for(int i = 0; i < total; ++i) { 
		glm::vec4 pt;
		fin >> pt.x;
		fin >> pt.y;
		pt.z = 0.0f;
		pt.w = 1.0f;

		vertices.push_back(pt);
	}

//Is the last point touching the Y-axis (closing the polyline)?
	if (vertices[total - 1].x != 0.0f) {
		glm::vec4 pt;
		pt.x = 0.0f;
		pt.y = vertices[total - 1].y;
		pt.z = 0.0f;
		pt.w = 1.0f;

		vertices.push_back(pt);
		++total;
	}

//Build the geometry
	buildGeometry();

//Get the mesh ready for the buffer!
	mesh.dump();

//Allocate the buffer space
	Geometry::buildBuffer(mesh.total, mesh.colors, mesh.normals, mesh.points);
}

void Surfrev::reset(bool bufferReady) {
	Geometry::masterReset(bufferReady);
}