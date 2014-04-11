#ifndef QUIZ02_VS2012_H
#define QUIZ02_VS2012_H

#include <QtWidgets/QMainWindow>
#include "ui_quiz02_vs2012.h"

class Quiz02_VS2012 : public QMainWindow
{
	Q_OBJECT

public:
	Quiz02_VS2012(QWidget *parent = 0);
	~Quiz02_VS2012();

private:
	Ui::Quiz02_VS2012Class ui;
};

#endif // QUIZ02_VS2012_H
