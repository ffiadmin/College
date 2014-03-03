#include "Axes.h"

Axes::Axes(Camera *camera, Shader *shader) : camera(camera), shader(shader) { }
Axes::~Axes() { }

void Axes::draw() {
	camera->mWVP = xLine.getWorldMatrix() * camera->mView * camera->mProj;
	shader->mfxWVPVar->SetMatrix(static_cast<float*>(camera->mWVP));
	xLine.setMTech(shader->mTech);
	xLine.draw();
	
	camera->mWVP = yLine.getWorldMatrix() * camera->mView * camera->mProj;
	shader->mfxWVPVar->SetMatrix(static_cast<float*>(camera->mWVP));
	yLine.setMTech(shader->mTech);
	yLine.draw();

	camera->mWVP = zLine.getWorldMatrix() * camera->mView * camera->mProj;
	shader->mfxWVPVar->SetMatrix(static_cast<float*>(camera->mWVP));
	zLine.setMTech(shader->mTech);
	zLine.draw();
}

void Axes::init() {
	line1.init(shader->md3dDevice, 10.0f, GREEN);
	line2.init(shader->md3dDevice, 10.0f, BLUE);
	line3.init(shader->md3dDevice, 10.0f, RED);

	xLine.init(&line1, Vector3(0,0,0), 5);
	xLine.setPosition(Vector3(0,0,0));
	yLine.init(&line2, Vector3(0,0,0), 5);
	yLine.setPosition(Vector3(0,0,0));
	yLine.setRotationZ(ToRadian(90));
	zLine.init(&line3, Vector3(0,0,0), 5);
	zLine.setPosition(Vector3(0,0,0));
	zLine.setRotationY(ToRadian(90));
}

void Axes::update(float dt) {
	xLine.update(dt);
	yLine.update(dt);
	zLine.update(dt);
}