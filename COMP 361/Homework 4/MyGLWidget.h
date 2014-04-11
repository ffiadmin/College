/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for displaying a QT window. 
*/

#pragma once
#define _USE_MATH_DEFINES
#define GLEW_STATIC

#include "Camera.h"
#include "Cube.h"
#include "Extrusion.h"
#include "Light.h"
#include "Shader.h"
#include "Surfrev.h"

#include <cmath>
#include <QGLWidget>
#include <string>

using std::string;

namespace widgetNS {
//Default camera position
	const int       DEF_LEFT_RIGHT = 0;
	const int       DEF_UP_DOWN    = 45;
	const int       DEF_ZOOM       = 15;

//Input file
	const char      INPUT_FILE[]   = "extrusion1.dat";

//Light position
	const glm::vec3 LIGHT_POS      = glm::vec3(0.0f, 20.0f, 0.0f);

//Shader files
	const char      SHADER_CLR[]   = "color_xforms.frag";
	const char      SHADER_VERT[]  = "color_xforms.vert";
}

class MyGLWidget : public QGLWidget {
	Q_OBJECT

public : 
	MyGLWidget(QWidget *parent);
	~MyGLWidget();

	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

public slots : 
//Light positioning
	void lXDown();
	void lXUp();
	void lYDown();
	void lYUp();
	void lZDown();
	void lZUp();

//Camera positioning
	void rLR(int value);
	void rUD(int value);
	void zoom(int value);

//Input file
	void updateFile(string file);

private : 
	Camera *cam;
	Cube *cube;
	Extrusion *ext;
	Light *lightSource;
	//Surfrev *rev;
	Shader *shader;

	glm::vec3 light;
	float panRadius, phi, radius, theta;
	float x, y, z;
};