#include <iostream>
using namespace std;

class CompileBase {
public:
	void feature() { cout << "A generic feature" << endl; }
};

class CompileSpecific : public CompileBase {
public:
	void feature() { cout << "Blinking lights!" << endl; }
};

class VirtualBase {
public:
	virtual void feature() { cout << "Still a generic feature" << endl; }
};

class VirtualSpecific : public VirtualBase {
public:
	void feature() { cout << "Even better blinking lights!" << endl; }
};

int main() {
	CompileBase cb;
	cb.feature();

	CompileSpecific cs;
	cs.feature();

	VirtualBase vb;
	vb.feature();

	VirtualSpecific vs;
	vs.feature();

	return 0;
}