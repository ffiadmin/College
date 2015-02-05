#include <iostream>
using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

int min(int x, int y) {
	return x > y ? y : x;
}

int gcd(int x, int y) {
	int large = max(x, y);
	int small = min(x, y);

	while(small > 0) {
		int temp = small;
		small = min(large - small, temp);
		large = max(large - small, temp);
	}

	return large;
}

int rgcd(int x, int y) {
	int large = x > y ? x : y;
	int small = x > y ? y : x;

	if(small > 0) {
		rgcd(large - small, small);
	} else {
		return large;
	}
}

int main() {
	cout << gcd(9, 3) << endl;
	cout << gcd(121, 11) << endl;
	cout << gcd(144, 12) << endl;
	cout << gcd(625, 25) << endl;
	cout << gcd(625, 24) << endl;

	cout << rgcd(9, 3) << endl;
	cout << rgcd(121, 11) << endl;
	cout << rgcd(144, 12) << endl;
	cout << rgcd(625, 25) << endl;
	cout << rgcd(625, 24) << endl;

	return 0;
}