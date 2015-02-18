#include <iostream>
#include <vector>
using namespace std;

class Friendly {
public:
	void operator()() {
		cout << "Hello World" << endl;
	}
};

void hi();

int main() {
//Create the table
	//vector<void(*)()> table;
	//table.push_back(hi);
	//table.push_back(hi);

//Call all the functions in the table
	//table[0]();
	//table[1]();

//Create the table
	vector<Friendly> table(2);

//Call each of the objects in the
	table[0]();
	table[1]();

	return 0;
}

void hi() {
	cout << "Hello World" << endl;
}