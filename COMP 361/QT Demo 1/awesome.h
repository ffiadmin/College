#ifndef AWESOME_H
#define AWESOME_H

#include <QtWidgets/QMainWindow>
#include "ui_awesome.h"

class Awesome : public QMainWindow
{
	Q_OBJECT

public:
	Awesome(QWidget *parent = 0);
	~Awesome();

private:
	Ui::AwesomeClass ui;
};

#endif // AWESOME_H
