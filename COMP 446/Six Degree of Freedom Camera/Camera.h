#ifndef _CAMERA_H                // Prevent multiple definitions if this 
#define _CAMERA_H 

#include "constants.h"
#include "d3dUtil.h"
#include "d3dApp.h"
#include <d3dx9math.h>
#include "input.h"

class Camera
{
public:
	Camera();
	~Camera();
	void init(Vector3 position, Vector3 direction, Vector3 _lookAt);
	Matrix getViewMatrix() {return mView;}
	Matrix getProjectionMatrix() {return mProj;}
	void update(float dt);
	void setPosition(Vector3 pos) {position = pos;}
	Vector3 getPosition() {return position;}
	void setDirection(Vector3 dir) {direction = dir;}
	Vector3 getDirection() {return direction;}
	float getSpeed () {return speed;}
	void setSpeed(float s) {speed = s;}
	float getFoV() {return FoV;}
	void setFoV(float fov){FoV = fov;}
	void setPerspective();
	void setPitch(float p) {pitch = p;}
private:
	Matrix mView;
	Matrix mProj;
	Vector3 position;
	Vector3 direction;
	float speed;
	float aspectRatio;
	float FoV;
	float nearClippingPlane;
	float farClippingPlane;
	Vector3 lookAt;
	Vector3 up;
	Vector3 right;
	float yaw;
	float pitch;
	float roll;

	float moveLR;
	float moveBF;
	D3DXMATRIX rot;
	D3DXVECTOR3 defForward;
	D3DXVECTOR3 defRight;
	D3DXVECTOR3 forward;
};
#endif