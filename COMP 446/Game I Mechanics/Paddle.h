#pragma once

#include "Box.h"
#include "Camera.h"
#include "d3dUtil.h"
#include "GameObject.h"
#include "input.h"
#include "Shader.h"
#include <Windows.h>

namespace paddleNS {
	const D3DXCOLOR COLOR       = BLACK;
	const int       SCALE       = 1;
	const bool      SHOW_CURSOR = true;
	const int       Z_POSITION  = 0;
}

class Paddle {
public : 
	Paddle(Camera *camera, Shader *shader);
	~Paddle();

	void draw();
	void init(HWND hWnd);
	void update(float dt);

private : 
	Box box;
	Camera *camera;
	GameObject paddle;
	Input input;
	Shader *shader;

	int x, y;
	bool down;
};