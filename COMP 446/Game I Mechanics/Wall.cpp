#include "Wall.h"

Wall::Wall(Camera *camera, Shader *shader) : camera(camera), shader(shader) { }
Wall::~Wall() { }

void Wall::draw() {
//Draw the wall!
	for(int i = 0; i < wallNS::SIDES; ++i) {
		camera->mWVP = quad[i].getWorld() * camera->mView * camera->mProj;
		shader->mfxWVPVar->SetMatrix(static_cast<float*>(camera->mWVP));
		shader->mTech->GetDesc(&shader->technique);

		for(UINT p = 0; p < shader->technique.Passes; ++p) {
			shader->mTech->GetPassByIndex(p)->Apply(0);
			quad[i].draw();
		}
	}
}

void Wall::init() {
//Up
	quad[0].init(shader->md3dDevice, wallNS::SCALE, wallNS::COLORS[0]);
	quad[0].setPosition(D3DXVECTOR3(0, wallNS::CENTER_DIST, 0));
	quad[0].setRotYAngle(ToRadian(45));

//Right
	quad[1].init(shader->md3dDevice, wallNS::SCALE, wallNS::COLORS[1]);
	quad[1].setPosition(D3DXVECTOR3(-wallNS::CENTER_DIST, 0, 0));
	quad[1].setRotYAngle(ToRadian(45));
	quad[1].setRotZAngle(ToRadian(90));

//Down
	quad[2].init(shader->md3dDevice, wallNS::SCALE, wallNS::COLORS[2]);
	quad[2].setPosition(D3DXVECTOR3(0, -wallNS::CENTER_DIST, 0));
	quad[2].setRotYAngle(ToRadian(45));

//Left
	quad[3].init(shader->md3dDevice, wallNS::SCALE, wallNS::COLORS[3]);
	quad[3].setPosition(D3DXVECTOR3(wallNS::CENTER_DIST, 0, 0));
	quad[3].setRotYAngle(ToRadian(45));
	quad[3].setRotZAngle(ToRadian(90));
}

void Wall::update(float dt) {
	for (int i = 0; i < wallNS::SIDES; ++i) {
		quad[i].update(dt);
	}
}