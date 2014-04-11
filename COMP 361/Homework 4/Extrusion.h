/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: The class to create extrusion geometry
*/

#pragma once

#include "FileNotFound.h"
#include "Geometry.h"
#include "InvalidObjectType.h"
#include "Mesh.h"

#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

namespace extrusionNS {
	const char INPUT_FILE_TYPE[] = "extrusion";
}

class Extrusion : public Geometry {
public : 
	Extrusion(string configFile, Shader *shader);
	~Extrusion();

//Public interface for object manipulation and display
	virtual void draw();

private : 
	virtual void buildGeometry();
	bool isConvex();
	void reloadFile(string configFile) throw(FileNotFound, InvalidObjectType);
	void reset(bool bufferReady);

//Polygon data
	Mesh mesh;
	vector<glm::vec3> vertices;

	bool convex;
	float height;
	int total;
};