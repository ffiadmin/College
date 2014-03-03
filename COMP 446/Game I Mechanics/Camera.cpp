#include "Camera.h"

Camera::Camera(int windowWidth, int windowHeight) : windowHeight(windowHeight), windowWidth(windowWidth) {
	D3DXMatrixIdentity(&mProj);
	D3DXMatrixIdentity(&mView);
	D3DXMatrixIdentity(&mWVP);
}

Camera::~Camera() { }

void Camera::resize() {
	float aspectRatio = static_cast<float>(windowWidth) / windowHeight;
	D3DXMatrixPerspectiveFovLH(&mProj, cameraNS::FIELD_OF_VIEW, aspectRatio, cameraNS::CLIP_NEAR, cameraNS::CLIP_FAR);
}

void Camera::update() {
	D3DXMatrixLookAtLH(&mView, &cameraNS::CAMERA_AT, &cameraNS::CENTER, &cameraNS::UP);
}