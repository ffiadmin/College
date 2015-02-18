
#include <cstdint>
#include <iostream>
using namespace std;

struct RGB {
public:
	uint8_t R; //This is an 8-bit type
	uint8_t G;
	uint8_t B;
};

RGB seperate(unsigned int in);

int main() {
	RGB colors = seperate(1000000);
	cout << "R: " << (unsigned int)colors.R << " "
		 << "G: " << (unsigned int)colors.G << " "
		 << "B: " << (unsigned int)colors.B << endl;

	return 0;
}

RGB seperate(unsigned int in) {
	RGB ret;
	ret.R = in & 0xFF;
	ret.G = (in >> 8) & 0xFF;
	ret.B = (in >> 16);

	return ret;
}