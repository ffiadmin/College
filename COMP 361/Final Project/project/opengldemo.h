#ifndef OPENGLDEMO_H
#define OPENGLDEMO_H

#include <QtWidgets/QMainWindow>
#include "ui_opengldemo.h"

class OpenGLdemo : public QMainWindow
{
	Q_OBJECT

public:
	OpenGLdemo(QWidget *parent = 0);
	~OpenGLdemo();

private:
	Ui::OpenGLdemoClass ui;
};

#endif // OPENGLDEMO_H
