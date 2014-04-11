/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: The class to hold and manipulate a mesh data structure
*/

#include "Mesh.h"

Mesh::Mesh(Colors color) : color(color) { }

Mesh::~Mesh() {
	delete[] colors;
	delete[] normals;
	delete[] points;
}

void Mesh::addTriangle(glm::vec3 one, glm::vec3 two, glm::vec3 three) {
	pts.push_back(glm::vec4(one, 1.0f));
	pts.push_back(glm::vec4(two, 1.0f));
	pts.push_back(glm::vec4(three, 1.0f));

	total = pts.size();
}

void Mesh::addTriangle(glm::vec4 one, glm::vec4 two, glm::vec4 three) {
	pts.push_back(one);
	pts.push_back(two);
	pts.push_back(three);

	total = pts.size();
}

void Mesh::dump() {
	total = pts.size();

//Put all of the vertices into an array
	colors = new glm::vec3[total];
	normals = new glm::vec4[total];
	points = new glm::vec4[total];

	glm::vec3 current, next, previous;

	for(int i = 0; i < total; ++i) {
		colors[i] = geometryNS::COLORS[color];
		points[i] = pts[i];

	//Calculate normals, special case
		if (i == 0) {
			current = glm::vec3(pts[0].x, pts[0].y, pts[0].z);
			next = glm::vec3(pts[1].x, pts[1].y, pts[1].z);
			previous = glm::vec3(pts[total - 1].x, pts[total - 1].y, pts[total - 1].z);
		} else if (i == total - 1) {
			current = glm::vec3(pts[i].x, pts[i].y, pts[i].z);
			next = glm::vec3(pts[0].x, pts[0].y, pts[0].z);
			previous = glm::vec3(pts[i - 1].x, pts[i - 1].y, pts[i - 1].z);
		} else {
			current = glm::vec3(pts[i].x, pts[i].y, pts[i].z);
			next = glm::vec3(pts[i + 1].x, pts[i + 1].y, pts[i + 1].z);
			previous = glm::vec3(pts[i - 1].x, pts[i - 1].y, pts[i - 1].z);
		}

	//HACKTASTIC    VVV
		normals[i] = -glm::vec4(glm::normalize(glm::cross(next - current, previous - current)), 1.0f);
	}
}