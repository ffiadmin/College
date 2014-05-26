#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "../glm/glm.hpp"
#include <stdlib.h>
#include "../glm/gtc/matrix_transform.hpp"
#include <vector>
using std::vector;
using glm::vec3;
using glm::vec4;
using glm::mat4;

class Face {
public : 
	Face();
	~Face();

	void addVertex(vec4 pos);
	bool isConvex();
	int size();
	vector<Face> triangulate();

	vector<vec3> getColors();
	vector<int> getIndices(int startIndex);
	vector<vec4> getNormals();
	vector<vec4> getVertices();
	
	void setColors(vec3 color);
	void setNormals(vec4 normal);
	
private : 
	vector<vec3> colors;
	vector<vec4> points;
	vector<vec4> normals;
};