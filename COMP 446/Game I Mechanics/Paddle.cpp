#include "Paddle.h"

Paddle::Paddle(Camera *camera, Shader *shader) : camera(camera), shader(shader) { }
Paddle::~Paddle() { }

void Paddle::draw() {
	//int x = input.getMouseX();
	//int y = input.getMouseY();

	if (!down) {
		if(GetAsyncKeyState('D') & 0x8000)	x--;
		if(GetAsyncKeyState('A') & 0x8000)	x++;
		if(GetAsyncKeyState('W') & 0x8000)	y++;
		if(GetAsyncKeyState('S') & 0x8000)	y--;
	}

	if ((GetAsyncKeyState('D') & 0x8000) ||
		(GetAsyncKeyState('A') & 0x8000) ||
		(GetAsyncKeyState('W') & 0x8000) ||
		(GetAsyncKeyState('S') & 0x8000)) {
			down = true;
	} else {
		down = false;
	}

	camera->mWVP = paddle.getWorldMatrix() * camera->mView * camera->mProj;
	shader->mfxWVPVar->SetMatrix(static_cast<float*>(camera->mWVP));
	paddle.setPosition(D3DXVECTOR3(x * 0.5f, y * 0.5f, paddleNS::Z_POSITION));
	paddle.setMTech(shader->mTech);
	paddle.draw();
}

void Paddle::init(HWND hWnd) {
	x = 0;
	y = 0;
	down = false;

//Hide the cursor
	ShowCursor(paddleNS::SHOW_CURSOR);
	input.initialize(hWnd, false);

//Initialize the cube
	box.init(shader->md3dDevice, paddleNS::SCALE, paddleNS::COLOR);

//Create the paddle
	paddle.init(&box, sqrt(2.0f), D3DXVECTOR3(0, 0, paddleNS::Z_POSITION), D3DXVECTOR3(0, 0, 0), 0, 1);
}

void Paddle::update(float dt) {
	paddle.update(dt);
}