/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: The class to create extrusion geometry
*/

#include "Extrusion.h"

Extrusion::Extrusion(string configFile, Shader *shader) : Geometry(shader), mesh(WHITE) {
	Geometry::masterReset(false);
	reloadFile(configFile);
}

Extrusion::~Extrusion() { }

void Extrusion::buildGeometry() {
	vector<glm::vec3> geometry;
	glm::vec3 offset = glm::vec3(0.0f, height, 0.0f);
	glm::vec3 start = vertices[0];

//Triangulate the end caps, if convex
	if (convex) {
	//Triangulate the base
	//Winding order in the opposite direction since you must see the bottom of the shape
		for(int i = 1; i < total - 1; ++i) { // total - 1 since the algorithm uses i + 1
			geometry.push_back(start);
			geometry.push_back(vertices[i]);
			geometry.push_back(vertices[i + 1]);

			mesh.addTriangle(start, vertices[i], vertices[i + 1]);
		}

	//Triangulate the top
		for(int i = 1; i < total - 1; ++i) {
			geometry.push_back(start + offset);
			geometry.push_back(vertices[i] + offset);
			geometry.push_back(vertices[i + 1] + offset);

			mesh.addTriangle(start + offset, vertices[i + 1] + offset, vertices[i] + offset);
		}
	}

//Triangulate the sides
	for(int i = 0; i < total - 1; ++i) { // Don't do the last side
	//Top-half triangle
		geometry.push_back(vertices[i]);
		geometry.push_back(vertices[i + 1] + offset);
		geometry.push_back(vertices[i] + offset);

		mesh.addTriangle(vertices[i], vertices[i + 1] + offset, vertices[i] + offset);

	//Bottom half triangle
		geometry.push_back(vertices[i]);
		geometry.push_back(vertices[i + 1]);
		geometry.push_back(vertices[i + 1] + offset);

		mesh.addTriangle(vertices[i], vertices[i + 1], vertices[i + 1] + offset);
	}

//Cover the last side
	int last = total - 1;

	geometry.push_back(vertices[last]);
	geometry.push_back(vertices[0] + offset);
	geometry.push_back(vertices[last] + offset);

	mesh.addTriangle(vertices[last], vertices[0] + offset, vertices[last] + offset);

	geometry.push_back(vertices[last]);
	geometry.push_back(vertices[0]);
	geometry.push_back(vertices[0] + offset);

	mesh.addTriangle(vertices[last], vertices[0], vertices[0] + offset);

//Empty the existing vertex vector and fill it back up with the above calculated points
	vertices.clear();
	vertices = geometry;
	total = vertices.size();
}

void Extrusion::draw() {
	Geometry::masterDraw();

	glDrawArrays(GL_TRIANGLES, 0, total);
}

bool Extrusion::isConvex() {
//Less than four points is always convex
	if (total < 4) return true;

//Determine if the points are convex
	glm::vec3 normal = glm::cross(vertices[1] - vertices[0], vertices[total - 1] - vertices[0]);
	glm::vec3 normNeg = -normal;
	glm::vec3 T;

	for(int i = 1; i < total - 1; ++i) { // total - 1 since the algorithm uses i + 1
		T = glm::cross(vertices[i + 1] - vertices[i], vertices[i - 1] - vertices[i]);
		if ((T.y < 0 && normNeg.y > 0) || (T.y > 0 && normal.y < 0)) return false;
	}

	return true;
}

void Extrusion::reloadFile(string configFile) throw(FileNotFound, InvalidObjectType) {
	ifstream fin(configFile);

	if (!fin.is_open()) {
		throw FileNotFound(configFile + " is missing and cannot be loaded.");
	}

//Determine if this is the correct file type
	string type;
	fin >> type;

	if (type != extrusionNS::INPUT_FILE_TYPE) {
		throw InvalidObjectType(type + " is not a valid object type from the input file. It should be " + extrusionNS::INPUT_FILE_TYPE + ".");
	}

//Determine the extrusion height
	fin >> height;

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

void Extrusion::reset(bool bufferReady) {
	Geometry::masterReset(bufferReady);
}