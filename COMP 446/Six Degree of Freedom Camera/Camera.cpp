#include "Camera.h"

Camera::Camera()
{
	speed = 10;
	FoV = 0.25*PI;
	aspectRatio = 480.0f/640.0f;
	nearClippingPlane = 1.0f;
	farClippingPlane = 1000.0f;
	up = Vector3(0.0f, 1.0f, 0.0f);
	position = Vector3(-10,0,0);
	lookAt = Vector3(0.0f, 0.0f, 0.0f);
	yaw = 0;
	roll = 0;
	pitch = 0;

	moveBF = 0.0f;
	moveLR = 0.0f;
	defForward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	defRight = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	forward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
}

Camera::~Camera()
{
	//nothing to deallocate
}

void Camera::init(Vector3 position, Vector3 direction, Vector3 _lookAt)
{
}

void Camera::setPerspective()
{
	D3DXMatrixPerspectiveFovLH(&mProj, FoV, aspectRatio, nearClippingPlane,farClippingPlane); 
}
void Camera::update(float dt)
{
//Configuration
	float speed = 0.005f;

//Camera movement input
	if(GetAsyncKeyState('A') & 0x8000) moveLR -= speed;
	if(GetAsyncKeyState('D') & 0x8000) moveLR += speed;
	if(GetAsyncKeyState('S') & 0x8000) moveBF -= speed;
	if(GetAsyncKeyState('W') & 0x8000) moveBF += speed;

	if(GetAsyncKeyState(VK_RIGHT) & 0x8000) yaw += speed;
	if(GetAsyncKeyState(VK_LEFT) & 0x8000) yaw -= speed;
	if(GetAsyncKeyState(VK_UP) & 0x8000) pitch < -1 ? -1 : (pitch -= speed);
	if(GetAsyncKeyState(VK_DOWN) & 0x8000) pitch > 1 ? 1 : (pitch += speed);

//Update the yaw and pitch
	D3DXMatrixRotationYawPitchRoll(&rot, yaw, pitch, 0);
	D3DXVec3TransformCoord(&lookAt, &defForward, &rot);
	D3DXVec3Normalize(&lookAt, &lookAt);

//Apply yaw
	D3DXMATRIX rotYTemp;
	D3DXMatrixRotationY(&rotYTemp, yaw);

//Transform UP, RIGHT, LOOKAT
	D3DXVec3TransformNormal(&right, &defRight, &rotYTemp);
	D3DXVec3TransformNormal(&up, &up, &rotYTemp);
	D3DXVec3TransformNormal(&forward, &defForward, &rotYTemp);

//Update camera position
	position += moveLR * right;
	position += moveBF * forward;

	moveLR = 0.0f;
	moveBF = 0.0f;

//Generate new matrix
	lookAt += position;

	D3DXMatrixLookAtLH(&mView, &position, &lookAt, &up);
}