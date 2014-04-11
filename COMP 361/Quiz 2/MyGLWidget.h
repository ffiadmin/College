#pragma once

#pragma region Library Includes
#define GLEW_STATIC
#include "glew.h"
#pragma comment(lib, "glew32s.lib")

#include <QGLWidget>
#include "glm/glm.hpp"

#include <vector>
#pragma endregion

class MyGLWidget : public QGLWidget {
	Q_OBJECT
public:
	MyGLWidget(QWidget*);
	~MyGLWidget(void);

	void initializeGL(void);
	void paintGL(void);
	void resizeGL(int, int);

public slots:
	void loadFile(QString);
	void orbitUp(void);
	void orbitDown(void);
	void orbitLeft(void);
	void orbitRight(void);
	void zoomIn(void);
	void zoomOut(void);

signals:
	void sendPlanarity(bool);

private:
	bool isPlanar;
	void fillBuffers(void);
	std::vector<glm::vec4> points;

	///// Should NOT need to change from here down!	//////
	char* textFileRead(const char*);
	void updateCamera(void);
	
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	unsigned int vbo;
	unsigned int cbo;
	unsigned int nbo;
	unsigned int ibo;
	unsigned int vLocation;
	unsigned int cLocation;
	unsigned int nLocation;

	unsigned int u_projLocation;
	unsigned int u_modelLocation;
	unsigned int u_lightLocation;

	glm::vec4 camPos;
	glm::vec4 camUp;
	glm::vec4 lightPos;
	float camDist;
	float camTheta;
	float camPsi;
};

