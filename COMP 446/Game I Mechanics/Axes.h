#pragma once

#include "Camera.h"
#include "d3dUtil.h"
#include "Line.h"
#include "LineObject.h"
#include "Shader.h"

class Axes {
public : 
	Axes(Camera *camera, Shader *shader);
	~Axes();

	void draw();
	void init();
	void update(float dt);

private : 
	Camera *camera;
	Line line1, line2, line3;
	LineObject xLine, yLine, zLine;
	Shader *shader;
};