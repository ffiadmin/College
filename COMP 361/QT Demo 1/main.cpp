#include "awesome.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Awesome w;
	w.show();
	return a.exec();
}
