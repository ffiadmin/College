#include <QLCDNumber>
#include <QTimer>

class MyLCD : public QLCDNumber
{
	Q_OBJECT

public:
	MyLCD(QWidget*);
	~MyLCD(void);

signals:
	void pass(void);
	void override(int);

public slots:
	void increment(void);
	void increment10(void);

private:
	QTimer* timer;
};

