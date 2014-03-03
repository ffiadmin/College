#pragma once

#include "Camera.h"
#include "d3dUtil.h"
#include "Quad.h"
#include "Shader.h"

namespace wallNS {
	const int       CENTER_DIST = 5;
	const D3DXCOLOR COLORS[]    = { RED, GREEN, CYAN, YELLOW }; // Up, Right, Down, Left
	const int       SCALE       = 50;
	const int       SIDES       = 4;
}

class Wall {
public : 
	Wall(Camera *camera, Shader *shader);
	~Wall();

	void draw();
	void init();
	void update(float dt);

private : 
	Camera *camera;
	Quad quad[wallNS::SIDES];      // UP, RIGHT, DOWN, LEFT
	Shader *shader;
};