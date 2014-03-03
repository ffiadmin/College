/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for displaying a QT window. 
*/

#include "MyGLWidget.h"

MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent) { }

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
	return;
//Parse the input file
	ifstream fout("input2.txt");

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
		c.applyScale(X, 3);
		c.applyScale(Y, 3);
		c.applyScale(Z, 3);
		c.present();
	c.end();
}

void MyGLWidget::resizeGL(int width, int height) {
	c.placeCamera(width, height);
}