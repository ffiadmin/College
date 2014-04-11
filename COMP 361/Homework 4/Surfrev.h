/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: The class to create surface revolution geometry
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

namespace surfrevNS {
	const char INPUT_FILE_TYPE[] = "surfrev";
}

class Surfrev : public Geometry {
public : 
	Surfrev(string configFile, Shader *shader);
	~Surfrev();

//Public interface for object manipulation and display
	virtual void draw();

private : 
	virtual void buildGeometry();
	void reloadFile(string configFile) throw(FileNotFound, InvalidObjectType);
	void reset(bool bufferReady);

//Polygon data
	Mesh mesh;
	vector<glm::vec4> vertices;

	int slices;
	int total;
};