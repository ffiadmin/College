#include "PlanarLabel.h"


PlanarLabel::PlanarLabel(QWidget* parent = 0) : QLabel(parent) {
}


PlanarLabel::~PlanarLabel() {
}

void PlanarLabel::setBool(bool isPlanar) {
	if(isPlanar) {
		setText("True");
	}
	else {
		setText("False");
	}
}