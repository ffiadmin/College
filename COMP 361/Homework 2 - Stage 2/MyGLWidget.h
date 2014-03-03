/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This main code for displaying a QT window. 
*/

#pragma once
#define GLEW_STATIC

#include "Box.h"
#include "Chair.h"
#include "Cube.h"
#include "glew.h"
#include "Table.h"

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <QGLWidget>
#include <vector>

using namespace std;

class MyGLWidget : public QGLWidget {
	Q_OBJECT

public : 
	MyGLWidget(QWidget*);
	~MyGLWidget();

	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

private : 
	Cube c;
	vector<void*> obj;
	float rad, x, y, z;

	void load(string input);

public slots:
	void updateFile(string file);
	void rLR(int value);
	void rUD(int value);
	void zoom(int value);
};