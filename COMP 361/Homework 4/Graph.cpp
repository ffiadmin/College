/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: This doesn't describe this class.
*/

#include "Graph.h"

Graph::Graph(Cube *cube) : cube(cube) {
	hasChildren = false;
	location = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

Graph::~Graph() {
	if (hasChildren) {
		for (int i = 0; i < children.size(); ++i) {
			delete children[i];
		}

		children.empty();
		hasChildren = false;
	}
}

void Graph::destroyChildren() {
	Graph::~Graph();
}

void Graph::graft(Graph *graph) {
	children.push_back(graph);
	hasChildren = true;
}

void Graph::visit() {
	cube->setRotation(rotation);
	cube->setScale(scale);
	cube->setTranslation(location);
	cube->draw();

	for (int i = 0; i < children.size(); ++i) {
		children[i]->visit();
	}
}