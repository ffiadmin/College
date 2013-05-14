#include <iostream>
using namespace std;

int big[1000];

int binarySR(int item, int lower, int upper);
int binarySI(int item, int lower, int upper);

int main() {
	for (int i = 0; i < 1000; ++i) {
		big[i] = i;
	}

	cout << binarySR(42, 0, 1000) << endl;
	cout << binarySI(42, 0, 1000) << endl;

	return 0;
}

int binarySR(int item, int lower, int upper) {
	int middle = lower + (upper - lower) / 2;
	
	if (middle == item) {
		return middle;
	} else if (middle > item) {
		return binarySR(item, lower, middle);
	} else {
		return binarySR(item, middle, upper);
	}
}

int binarySI(int item, int lower, int upper) {
	int middle;

	while(true) {
		middle = lower + (upper - lower) / 2;

		if (middle == item) {
			return middle;
		} else if (middle > item) {
			upper = middle;
		} else {
			lower = middle;
		}
	}
}