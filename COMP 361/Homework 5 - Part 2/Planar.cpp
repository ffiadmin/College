/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   April 6th, 2014
 Description: The class to draw planar or non-planar geometry
*/

#include "Planar.h"

Planar::Planar(string configFile, Shader *shader) : Geometry(shader), mesh(WHITE) {
	Geometry::masterReset(false);
	reloadFile(configFile);
}

Planar::~Planar() { }

void Planar::buildGeometry() {
//We're set if everything is planar
	if (planar) return;

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

void Planar::draw() {
	Geometry::masterDraw();

//	if (planar) {
		glDrawArrays(GL_POLYGON, 0, total);
//	} else {
//		glDrawElements(GL_TRIANGLES, total, GL_INT, mesh.points);
//	}
}

bool Planar::isConvex() {
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

bool Planar::isPlanar() {
	if (vertices.size() > 0) {
		glm::vec4 norm = glm::vec4(glm::normalize(vertices[0]), 1.0f);
		glm::vec4 T;
		
		for(int i = 1; i < vertices.size(); ++i) {
			T = glm::vec4(vertices[0], 1.0f) - glm::vec4(vertices[i], 1.0f);

			if (!glm::dot(T, norm)) {
				return false;
			}
		}
	}

	return true;
}

void Planar::reloadFile(string configFile) throw(FileNotFound) {
	ifstream fin(configFile);

	if (!fin.is_open()) {
		throw FileNotFound(configFile + " is missing and cannot be loaded.");
	}

//Determine the number of vertices
	fin >> total;

//Gather each of the vertices
	for(int i = 0; i < total; ++i) { 
		glm::vec3 pt;
		fin >> pt.x;
		fin >> pt.y;
		fin >> pt.z;

		vertices.push_back(pt);
	}

//Check for convexity
	convex = isConvex();

//Check for planarity
	planar = isPlanar();

//Build the geometry
	buildGeometry();

//Put all of the vertices into an array
	mesh.dump();

//Allocate the buffer space
	Geometry::buildBuffer(mesh.total, mesh.colors, mesh.normals, mesh.points);
}

void Planar::reset(bool bufferReady) {
	Geometry::masterReset(bufferReady);
}