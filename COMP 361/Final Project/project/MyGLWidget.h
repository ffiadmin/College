/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file defines the driver for this program, MyGLWidget
*/

#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "../glm/glm.hpp"
#include <QGLWidget>
#include <stdlib.h>

#include "../glm/gtc/matrix_transform.hpp"
#include "Cube.h"
#include "HECube.h"
#include "Table.h"
#include "Chair.h"
#include "Node.h"
#include "Camera.h"
#include "Light.h"
#include <vector>
#include <fstream>
#include <string>
#include "Utility.h"
//#include "Mesh.h"
#include "Extrusion.h"
#include "SurfRev.h"

//Ray Tracing stuff
#include "Ray.h"
#include "EasyBMP.h"

using std::string;
using std::ifstream;
using std::vector;
using glm::length;
class MyGLWidget : public QGLWidget
{
	Q_OBJECT
public:
	MyGLWidget(QWidget*);
	~MyGLWidget(void);

	void initializeGL(void);
	void paintGL(void);
	void resizeGL(int, int);
	vector<Node*> sceneGraph;

	//helper function to read shader source and put it in a char array
	//thanks to Swiftless.com
	char* textFileRead(const char*);

private:
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	unsigned int vLocation;

	unsigned int u_projLocation;
	unsigned int u_camMatrix;
	unsigned int u_modelMatrix;
	unsigned int u_lightPos;
	void importFile(string);

	Cube cube;
	Camera camera;
	Light light;
	Node*** grid;
	Node* currentObject;
	int currentLocation;
	vec3 traceRay(Ray ray);

public slots:
	void up(void);
	void down(void);
	void left(void);
	void right(void);
	void zoomIn();
	void zoomOut();
	void load(string);

	void lightUp();
	void lightDown();
	void lightXPlus();
	void lightXMinus();
	void lightZPlus();
	void lightZMinus();
	void cycleObjects();

	void moveXPlus();
	void moveXMinus();
	void moveZPlus();
	void moveZMinus();
	void rotatePlus();
	void rotateMinus();
	void scaleXPlus();
	void scaleXMinus();
	void scaleZPlus();
	void scaleZMinus();
	void scaleYPlus();
	void scaleYMinus();

	void rayTrace();

	
};