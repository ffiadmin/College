#pragma once
#define GLEW_STATIC
#include "glew.h"                 // Must be first!
#include <QGLWidget>
#include "../glm/glm.hpp"
#include <stdlib.h>
#include <QDebug>


class MyGLWidget : public QGLWidget {
public:
	MyGLWidget(QWidget*);
	~MyGLWidget(void);

	void initializeGL(void);
	void paintGL(void);
	void resizeGL(int, int);

	//helper function to read shader source and put it in a char array
	//thanks to Swiftless.com
	char* textFileRead(const char*);

	//some other helper functions
	void printLinkInfoLog(int);
	void printShaderInfoLog(int);

private:
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	unsigned int vbo;
	unsigned int vLocation;
};

