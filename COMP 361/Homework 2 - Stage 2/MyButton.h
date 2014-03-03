/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   February 20, 2014 
 Description: This main code triggering an event for an input. 
*/

#pragma once
#define GLEW_STATIC

#include <string>
#include <qtextedit.h>

using namespace std;

class MyButton : public QTextEdit {
	Q_OBJECT

public : 
	MyButton(QWidget*);
	~MyButton(void);

signals : 
	void file(string name);

public slots : 
	void loadFile() {
		emit file(this->toPlainText().toStdString());
	}
};