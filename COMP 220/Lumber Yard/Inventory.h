#include <fstream>

using std::ifstream;

class Inventory {
public : 
	Inventory(char *source);

private : 
	void initStorage();
	void parse();
	void read();
	
	int count[16][7][8];
	double boardfeet;

	ifstream fin;
};