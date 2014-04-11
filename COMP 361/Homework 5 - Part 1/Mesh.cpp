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

//Calculate the normals
	glm::vec3 current = one;
	glm::vec3 next = two;
	glm::vec3 previous = three;
	glm::vec4 normal = -glm::vec4(glm::normalize(glm::cross(next - current, previous - current)), 1.0f);

	norm.push_back(normal);
	norm.push_back(normal);
	norm.push_back(normal);

	total = pts.size();
}

void Mesh::addTriangle(glm::vec4 one, glm::vec4 two, glm::vec4 three) {
	pts.push_back(one);
	pts.push_back(two);
	pts.push_back(three);

//Calculate the normals
	glm::vec3 current = glm::vec3(one.x, one.y, one.z);
	glm::vec3 next = glm::vec3(two.x, two.y, two.z);
	glm::vec3 previous = glm::vec3(three.x, three.y, three.z);
	glm::vec4 normal = -glm::vec4(glm::normalize(glm::cross(next - current, previous - current)), 1.0f);

	norm.push_back(normal);
	norm.push_back(normal);
	norm.push_back(normal);

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
		normals[i] = norm[i];
		points[i] = pts[i];	
	}
}