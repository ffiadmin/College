#pragma once
#define GLEW_STATIC
#define BUFFER_OFFSET(bytes) ((GLvoid*)(bytes))
#include "glew.h"
#include "../glm/glm.hpp"
#include <QGLWidget>
#include <stdlib.h>

class MyGLWidget : public QGLWidget
{
public:
	MyGLWidget(QWidget*);
	~MyGLWidget(void);

	void initializeGL(void);
	void paintGL(void);
	void resizeGL(int, int);

	//helper function to read shader source and put it in a char array
	//thanks to Swiftless.com
	char* textFileRead(const char*);

private:
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	unsigned int vbo;
	unsigned int vLocation;

	unsigned int u_projLocation, u_modelMatrix;

	///GLuint model_view, projection;
};