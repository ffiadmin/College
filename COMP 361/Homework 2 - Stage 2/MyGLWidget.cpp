/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for displaying a QT window. 
*/

#include "MyGLWidget.h"

MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent), rad(10.0f), x(10), y(10), z(10) { }

MyGLWidget::~MyGLWidget() {
	for(int i = 0; i < obj.size(); ++i) {
		delete obj[i];
	}
}

void MyGLWidget::initializeGL() {
	c.loadFragmentShader("color_xforms.frag");
	c.loadVertexShader("color_xforms.vert");
	c.buildShader();
	c.buildBuffer();
	
	load("input.txt");
}

void MyGLWidget::load(string input) {
	ifstream fout(input);

	if (!fout.is_open()) {
		exit(1);
	}

	int floorX, floorY, total;
	int xIndex, zIndex, yRotation;
	int xScale, yScale, zScale;
	string type;

	fout >> floorX;
	fout >> floorY;
	fout >> total;

	for(int i = 0; i < total; ++i) {
		fout >> type;
		fout >> xIndex;
		fout >> zIndex;
		fout >> yRotation;
		fout >> xScale;
		fout >> yScale;
		fout >> zScale;

		if (type == "chair") {
			Chair *chair = new Chair (&c, xIndex, zIndex, yRotation, xScale, yScale, zScale);
			obj.push_back(chair);
		} else if (type == "table") {
			Table *table = new Table (&c, xIndex, zIndex, yRotation, xScale, yScale, zScale);
			obj.push_back(table);
		} else {
			Box *box = new Box (&c, xIndex, zIndex, yRotation, xScale, yScale, zScale);
			obj.push_back(box);
		}
	}

	fout.close();
}

void MyGLWidget::paintGL() {
	c.begin();
		c.applyColor(UP, CYAN);
		c.applyScale(X, 15);
		c.applyScale(Y, 0.01);
		c.applyScale(Z, 15);
		c.present();

		c.applyColor(ALL, GREEN);
		c.applyScale(X, 0.01);
		c.applyScale(Y, 6);
		c.applyScale(Z, 15);
		c.applyTranslation(15, 5, 0);
		c.present();

		c.applyColor(ALL, YELLOW);
		c.applyScale(X, 0.01);
		c.applyScale(Y, 6);
		c.applyScale(Z, 15);
		c.applyTranslation(-15, 5, 0);
		c.present();

		c.applyColor(ALL, MAGENTA);
		c.applyScale(X, 15);
		c.applyScale(Y, 6);
		c.applyScale(Z, 0.01);
		c.applyTranslation(0, 5, -15);
		c.present();
		
		c.applyColor(ALL, RED);
		c.applyScale(X, 15);
		c.applyScale(Y, 6);
		c.applyScale(Z, 0.01);
		c.applyTranslation(0, 5, 15);
		c.present();

		for(int i = 0; i < obj.size(); ++i) {
			static_cast<Chair*>(obj[i])->draw();
		}
	c.end();
}

void MyGLWidget::resizeGL(int width, int height) {
	c.placeCamera(width, height);
}

void MyGLWidget::rLR(int value) {
//Thank you: http://stackoverflow.com/a/14183865/663604
	x = cos(value * (M_PI / 180.f)) * rad;
	z = sin(value * (M_PI / 180.f)) * rad;

	c.applyEye(X, x);
	c.applyEye(Z, z);
	update();
}

void MyGLWidget::updateFile(string file) {
	obj.clear();
	load(file);
	update();
}

void MyGLWidget::rUD(int value) {
//Thank you: http://stackoverflow.com/a/14183865/663604
	x = sin(value * (M_PI / 180.f)) * rad;
	y = cos(value * (M_PI / 180.f)) * rad;
	z = sin(value * (M_PI / 180.f)) * rad;

	c.applyEye(X, x);
	c.applyEye(Y, y);
	c.applyEye(Z, z);
	update();
}
void MyGLWidget::zoom(int value) {
	x /= rad;
	y /= rad;
	z /= rad;

	rad = value;

	x *= rad;
	y *= rad;
	z *= rad;
	
	c.applyEye(X, x);
	c.applyEye(Y, y);
	c.applyEye(Z, z);
	update();
}