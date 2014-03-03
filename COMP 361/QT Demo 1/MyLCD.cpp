#include "MyLCD.h"


MyLCD::MyLCD(QWidget* parent) : QLCDNumber(parent) {
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(increment()));
	timer->start(1000);
}


MyLCD::~MyLCD(void) {
	timer->stop();
	delete timer;
}

void MyLCD::increment() {
	display(intValue() + 1);
}

void MyLCD::increment10() {
	if (intValue() + 10 >= 100) {
		display(intValue() - 90);
		emit pass();
		emit override(intValue());
	} else {
		display(intValue() + 10);
		emit override(intValue());
	}
}