#ifndef SHADERS_H
#define SHADERS_H

#include <QtWidgets/QMainWindow>
#include "ui_shaders.h"

class Shaders : public QMainWindow
{
	Q_OBJECT

public:
	Shaders(QWidget *parent = 0);
	~Shaders();

private:
	Ui::ShadersClass ui;
};

#endif // SHADERS_H
