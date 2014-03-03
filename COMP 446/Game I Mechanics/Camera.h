#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include <d3dx9math.h>

namespace cameraNS {
//Camera views
	const float       CLIP_FAR      = 1000.0f;
	const float       CLIP_NEAR     = 1.0f;
	const float       FIELD_OF_VIEW = 0.25f * M_PI;

//Camera position
	const D3DXVECTOR3 CAMERA_AT     = D3DXVECTOR3(0.0f, 0.0f, 15.0f);
	const D3DXVECTOR3 CENTER        = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	const D3DXVECTOR3 UP            = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
}

class Camera {
public : 
	Camera(int windowWidth, int windowHeight);
	~Camera();

	void resize();
	void update();

//Camera location and viewing matrices
	D3DXMATRIX mProj;
	D3DXMATRIX mView;
	D3DXMATRIX mWVP;

private : 
	int windowHeight;
	int windowWidth;
};