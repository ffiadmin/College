#pragma once

#include <QLabel>

class PlanarLabel : public QLabel {
	Q_OBJECT
public:
	PlanarLabel(QWidget*);
	~PlanarLabel(void);

public slots:
	void setBool(bool);
};

