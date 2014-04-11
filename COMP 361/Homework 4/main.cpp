#include "shaders.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Shaders w;
	w.show();
	return a.exec();
}
