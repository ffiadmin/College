//=============================================================================
// Color Cube App.cpp by Frank Luna (C) 2008 All Rights Reserved.
//=============================================================================

#include "Axes.h"
#include "Camera.h"
#include "Crumbler.h"
#include "d3dApp.h"
#include "Shader.h"
#include "Paddle.h"
#include "Wall.h"

class ColoredCubeApp : public D3DApp {
public : 
	ColoredCubeApp(HINSTANCE hInstance);
	~ColoredCubeApp();

	void drawScene(); 
	void initApp();
	void onResize();
	void updateScene(float dt);

private : 
	Axes axes;
	Camera cam;
	Crumbler crumbler;
	Shader shader;
	Paddle paddle;
	Wall wall;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR cmdLine, int showCmd) {
	#if defined(DEBUG) | defined(_DEBUG)
		_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	#endif

	ColoredCubeApp theApp(hInstance);
	theApp.initApp();
	return theApp.run();
}

ColoredCubeApp::ColoredCubeApp(HINSTANCE hInstance) : D3DApp(hInstance),
	axes(&cam, &shader), cam(mClientWidth, mClientHeight), crumbler(&cam, &shader),
	paddle(&cam, &shader), wall(&cam, &shader) { }

ColoredCubeApp::~ColoredCubeApp() {
	if(md3dDevice) md3dDevice->ClearState();
}

void ColoredCubeApp::initApp() {
	D3DApp::initApp();
	shader.init(md3dDevice);
	axes.init();
	crumbler.init();
	paddle.init(mhMainWnd);
	wall.init();
}

void ColoredCubeApp::onResize() {
	D3DApp::onResize();
	cam.resize();
}

void ColoredCubeApp::updateScene(float dt) {
	D3DApp::updateScene(dt);
	axes.update(dt);
	crumbler.update(dt);
	paddle.update(dt);
	wall.update(dt);
	cam.update();
}

void ColoredCubeApp::drawScene() {
	D3DApp::drawScene();
	axes.draw();
	shader.draw();
	crumbler.draw();
	paddle.draw();
	wall.draw();

	// We specify DT_NOCLIP, so we do not care about width/height of the rect.
	RECT R = {5, 5, 0, 0};
	mFont->DrawText(0, mFrameStats.c_str(), -1, &R, DT_NOCLIP, BLACK);
	mSwapChain->Present(0, 0);
}