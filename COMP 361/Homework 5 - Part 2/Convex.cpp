/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   April 6th, 2014
 Description: The class to draw convex geometry
*/

#include "Convex.h"

Convex::Convex(string configFile, Shader *shader) : Geometry(shader), mesh(WHITE) {
	Geometry::masterReset(false);
	reloadFile(configFile);
}

Convex::~Convex() { }

void Convex::buildGeometry() {
	vector<glm::vec3> geometry;
	glm::vec3 start = vertices[0];

//Triangulate the geometry, if convex
	if (convex) {
		for(int i = 1; i < total - 1; ++i) {
			geometry.push_back(start);
			geometry.push_back(vertices[i]);
			geometry.push_back(vertices[i + 1]);

			mesh.addTriangle(start, vertices[i], vertices[i + 1]);
		}
	}

//Empty the existing vertex vector and fill it back up with the above calculated points
	vertices.clear();
	vertices = geometry;
	total = vertices.size();
}

void Convex::draw() {
	Geometry::masterDraw();

	glDrawArrays(GL_TRIANGLES, 0, total);
}

bool Convex::isConvex() {
//Less than four points is always convex
	if (total < 4) return true;

//Determine if the points are convex
	glm::vec3 normal = glm::normalize(glm::cross(vertices[1] - vertices[0], vertices[total - 1] - vertices[0]));
	glm::vec3 normNeg = -normal;
	glm::vec3 T;

	for(int i = 1; i < total - 1; ++i) { // total - 1 since the algorithm uses i + 1
		T = glm::normalize(glm::cross(vertices[i + 1] - vertices[i], vertices[i - 1] - vertices[i]));
		if (T == normNeg) return false;
	}

	return true;
}

void Convex::reloadFile(string configFile) throw(FileNotFound, InvalidObjectType) {
	ifstream fin(configFile);

	if (!fin.is_open()) {
		throw FileNotFound(configFile + " is missing and cannot be loaded.");
	}

//Determine if this is the correct file type
	string type;
	fin >> type;

	if (type != convexNS::INPUT_FILE_TYPE) {
		throw InvalidObjectType(type + " is not a valid object type from the input file. It should be " + convexNS::INPUT_FILE_TYPE + ".");
	}

//Determine the number of vertices
	fin >> total;
	--total; // The first and last are the same vertex

//Gather each of the vertices
	for(int i = 0; i < total; ++i) { 
		glm::vec3 pt;
		fin >> pt.x;
		pt.y = 0.0f;
		fin >> pt.z;

		vertices.push_back(pt);
	}

//Check for convexity
	convex = isConvex();

//Build the geometry
	buildGeometry();

//Put all of the vertices into an array
	mesh.dump();

//Allocate the buffer space
	Geometry::buildBuffer(mesh.total, mesh.colors, mesh.normals, mesh.points);
}

void Convex::reset(bool bufferReady) {
	Geometry::masterReset(bufferReady);
}