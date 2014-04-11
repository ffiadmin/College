/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   April 6th, 2014
 Description: The class to draw planar or non-planar geometry
*/

#pragma once

#include "FileNotFound.h"
#include "Geometry.h"
#include "Mesh.h"

#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

class Planar : public Geometry {
public : 
	Planar(string configFile, Shader *shader);
	~Planar();

//Public interface for object manipulation and display
	virtual void draw();
	void reloadFile(string configFile) throw(FileNotFound);

private : 
	virtual void buildGeometry();
	bool isConvex();
	bool isPlanar();
	void reset(bool bufferReady);

//Polygon data
	Mesh mesh;
	vector<glm::vec3> vertices;

	bool convex;
	bool planar;
	int total;
};