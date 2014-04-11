/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The class for rendering all objects from a configuration file. 
*/

#include "Scene.h"

Scene::Scene(string configFile, Shader *shader) {
//Initialize the variables
	floorDim = glm::vec3(0.0f, 0.0f, 0.0f);
	itemLoc = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
	unitSize = 1.0f;

//Create the necessary objects
	cube = new Cube(shader);
	graph = new Graph(cube);
	light = new Light(cube, shader);

//Load the config file
	reloadFile(configFile);
}

Scene::~Scene() {
	delete cube;
	delete graph;
	delete light;
}

void Scene::draw() {
	cube->begin();
	graph->visit();
	light->draw();
	cube->end();
}

void Scene::reloadFile(string configFile) throw(FileNotFound, InvalidObjectType) {
	ifstream fin(configFile);

	if (!fin.is_open()) {
		throw FileNotFound(configFile + " is missing and cannot be loaded.");
	}

//Delete the old scene
	delete graph;
	graph = new Graph(cube);

//Initial floor dimensions and number of items
	fin >> floorDim.x;
	fin >> floorDim.z;
	fin >> iterations;

	for(int i = 0; i < iterations; ++i) {
	//Information for each item supplied by the configuration file
		fin >> type;
		fin >> itemLoc.x;
		fin >> itemLoc.z;
		fin >> rotation.y;
		fin >> scale.x;
		fin >> scale.y;
		fin >> scale.z;

	//Create the respective items
		CubeObject *obj;

		if (type == "box") {
			obj = new Box(cube);
		} else if (type == "chair") {
			obj = new Chair(cube);
		} else if (type == "table") {
			obj = new Table(cube);
		} else {
			throw InvalidObjectType(type + " is not a valid object type.");
		}

		obj->setRotation(Y, rotation.y);
		obj->setScale(scale);
		obj->setTranslation(glm::vec3(itemLoc.x * 5.0f, 0.0f, itemLoc.z * 5.0f));
		obj->init();
		graph->graft(obj->graph);

		if (obj->getUnitLength() > unitSize) unitSize = obj->getUnitLength();
		if (obj->getUnitWidth() > unitSize) unitSize = obj->getUnitWidth();
	}

//Create (or re-create) the floor, based on the dimensions and unit size
	graph->scale = glm::vec3(floorDim.x * unitSize, sceneNS::FLOOR_HEIGHT, floorDim.z * unitSize);

	fin.close();
}