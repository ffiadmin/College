#include "Crumbler.h"

Crumbler::Crumbler(Camera *camera, Shader *shader) : camera(camera), shader(shader) {
	total = crumblerNS::PER_ROW * crumblerNS::PER_ROW;
	srand(time(NULL));
}

Crumbler::~Crumbler() { }

void Crumbler::draw() {
	for(int i = 0; i < total; ++i) {
		camera->mWVP = crumble[i].getWorldMatrix() * camera->mView * camera->mProj;
		shader->mfxWVPVar->SetMatrix(static_cast<float*>(camera->mWVP));
		crumble[i].setMTech(shader->mTech);
		crumble[i].draw();
	}
}

void Crumbler::init() {
//Initialize the cube
	box.init(shader->md3dDevice, crumblerNS::SIDE_LENGTH, crumblerNS::COLOR);

//Initialize and place the cubes
	int row = crumblerNS::PER_ROW;
	int x = 0, y = 0;

	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < row; ++j) {
			x = /*crumblerNS::LOWER_LEFT.x - */j * crumblerNS::RENDER_GAP;
			y = /*crumblerNS::LOWER_LEFT.y - */i * crumblerNS::RENDER_GAP;

			crumble[row * i + j].init(&box, sqrt(2.0f), D3DXVECTOR3(x, y, crumblerNS::Z_POSITION), D3DXVECTOR3(0, 0, rand() % 7 + 3), 0, 1);
		}
	}
}

void Crumbler::update(float dt) {
	for(int i = 0; i < total; ++i) {
		crumble[i].update(dt);
	}
}