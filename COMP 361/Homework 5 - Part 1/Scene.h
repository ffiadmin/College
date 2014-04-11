/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The class for rendering all objects from a configuration file. 
*/

#pragma once

#include "Box.h"
#include "Chair.h"
#include "Cube.h"
#include "FileNotFound.h"
#include "Graph.h"
#include "InvalidObjectType.h"
#include "Light.h"
#include "Shader.h"
#include "Table.h"

#include <fstream>
#include <string>

using std::ifstream;
using std::string;

namespace sceneNS {
//Floor
	const Colors FLOOR_COLOR  = CYAN;
	const float  FLOOR_HEIGHT = 0.01f;
	const float  FLOOR_LENGTH = 15.0f; // X direction
	const float  FLOOR_WIDTH  = 15.0f; // Z direction
}

class Scene {
public : 
	Scene(string configFile, Shader *shader);
	~Scene();
	
	Light *light;

	void draw();
	void reloadFile(string configFile) throw(FileNotFound, InvalidObjectType);

private : 
	Cube *cube;
	Graph *graph;

//Item placement, dimensions, and appearance
	glm::vec3 floorDim;
	glm::vec3 itemLoc;
	glm::vec3 rotation;
	glm::vec3 scale;
	float unitSize;

//File parsing data
	int iterations;
	string type;
};