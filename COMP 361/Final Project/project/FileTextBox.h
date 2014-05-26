#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "../glm/glm.hpp"
#include <QLineEdit>
#include <stdlib.h>
#include <string>
using std::string;

class FileTextBox :
	public QLineEdit
{
	Q_OBJECT
public:
	FileTextBox(QWidget*);
	~FileTextBox(void);

signals:
	string sendFilename(string);
		
public slots:
	void buttonInput(void);
};

