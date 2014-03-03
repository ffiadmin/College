#pragma once

#include "Box.h"
#include "Camera.h"
#include <cstdlib>
#include <ctime>
#include "GameObject.h"
#include "Shader.h"

namespace crumblerNS {
	const D3DXCOLOR   COLOR       = BEACH_SAND;
	const D3DXVECTOR2 LOWER_LEFT  = D3DXVECTOR2(-4, -4);
	const int         PER_ROW     = 8;
	const int         RENDER_GAP  = 2;
	const int         SIDE_LENGTH = 1;
	const int         Z_POSITION  = -25.0f;
}

class Crumbler {
public:
	Crumbler(Camera *camera, Shader *shader);
	~Crumbler();

	void draw();
	void init();
	void update(float dt);

private : 
	Box box;
	Camera *camera;
	GameObject crumble[crumblerNS::PER_ROW * crumblerNS::PER_ROW];
	Shader *shader;

	int total;
};