/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for displaying a QT window. 
*/

#include "MyGLWidget.h"

MyGLWidget::MyGLWidget(QWidget *parent) : QGLWidget(parent) {
	light = widgetNS::LIGHT_POS;

	panRadius = 1.0f;
	radius = 1.0f;
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
}

MyGLWidget::~MyGLWidget() {
	delete cam;
	delete scene;
	delete shader;
}

void MyGLWidget::initializeGL() {
	shader = new Shader(widgetNS::SHADER_CLR, widgetNS::SHADER_VERT);
	cam = new Camera(shader);

//Load the scene
	try {
		scene = new Scene(widgetNS::INPUT_FILE, shader);
	} catch (FileNotFound e) {
		exit(1);
	} catch (InvalidObjectType e) {
		exit(1);
	}

//Set the default view
	rLR(widgetNS::DEF_LEFT_RIGHT);
	rUD(widgetNS::DEF_UP_DOWN);
	zoom(widgetNS::DEF_ZOOM);
}

void MyGLWidget::lXDown() {
	scene->light->setPosition(X, --light.x);
	update();
}

void MyGLWidget::lXUp() {
	scene->light->setPosition(X, ++light.x);
	update();
}

void MyGLWidget::lYDown() {
	scene->light->setPosition(Y, --light.y);
	update();
}

void MyGLWidget::lYUp() {
	scene->light->setPosition(Y, ++light.y);
	update();
}

void MyGLWidget::lZDown() {
	scene->light->setPosition(Z, --light.z);
	update();
}

void MyGLWidget::lZUp(){ 
	scene->light->setPosition(Z, ++light.z);
	update();
}

void MyGLWidget::paintGL() {
	scene->draw();
}

void MyGLWidget::resizeGL(int width, int height) {
	cam->placeCamera(width, height);
}

void MyGLWidget::rLR(int value) {
	theta = static_cast<float>(value) * (M_PI / 180.0f);

//Calculate X and Z
	x = sin(theta) * panRadius;
	z = cos(theta) * panRadius;

//Update the camera position
	cam->setEye(X, x);
	cam->setEye(Z, z);
	update();
}

void MyGLWidget::rUD(int value) {
	phi = static_cast<float>(value) * (M_PI / 180.0f);

//Calculate X, Y, and Z
	panRadius = cos(phi) * radius;
	x = sin(theta) * panRadius;
	y = sin(phi) * radius;
	z = cos(theta) * panRadius;
	
//Update the camera position
	cam->setEye(glm::vec3(x, y, z));
	update();
}

void MyGLWidget::updateFile(string file) {
	try {
		scene->reloadFile(file);
	} catch (FileNotFound e) {
		exit(1);
	} catch (InvalidObjectType e) {
		exit(1);
	}

	update();
}

void MyGLWidget::zoom(int value) {
	x /= radius;
	y /= radius;
	z /= radius;

	radius = value;
	panRadius = cos(phi) * radius;

	x *= radius;
	y *= radius;
	z *= radius;
	
	cam->setEye(glm::vec3(x, y, z));
	update();
}