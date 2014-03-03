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

#include <cstdlib>
#include <fstream>
#include <string>
#include <QGLWidget>
#include <vector>

using std::ifstream;
using std::string;

class MyGLWidget : public QGLWidget {
public : 
	MyGLWidget(QWidget*);
	~MyGLWidget();

	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

private : 
	Cube c;
	vector<void*> obj;
};