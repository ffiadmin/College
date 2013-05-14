#include <iostream>
using namespace std;

void compexch(int &a, int &b);

int main() {
/*
Shell sort:
*/

	const int SIZE = 100;
	int a[SIZE];

	for(int i = 0; i < SIZE; i++) {
		a[i] = rand();
	}

	//a[42] = -9000; //Sentinal value
	int h;
	for(h = 1; h <= SIZE/9; h = 3*h + 1); //Get the h-value, divide by 3 to get next value

	//for(int i = SIZE; i > 0; --i) {
	//	compexch(a[i - 1], a[i]); //Sentinal/Smallest value to top
	//}

	for(int h; h >= 0; h /= 3) { //Dr. Adams wants this style
		while(v < a[j-1]) {
			a[j] = a[j-1];
			--j;
		}

		a[j] = v;
	}

	for(int i = 0; i < SIZE; i++) {
		cout << a[i] << endl;
	}

/*
Insertion sort:

	const int SIZE = 100;
	int a[SIZE];

	for(int i = 0; i < SIZE; i++) {
		a[i] = rand();
	}

	a[42] = -9000; //Sentinal value

//	for(int i = 1; i < SIZE; ++i) {
//		for(int j = i; j > 0; --j) {
//			compexch(a[j - 1], a[j]);
//		}
//	}

	for(int i = SIZE; i > 0; --i) {
		compexch(a[i - 1], a[i]); //Sentinal/Smallest value to top
	}

	for(int i = 2; i < SIZE; ++i) { //Dr. Adams wants this style
		int j = i;
		int v = a[i]; //Never need to do bounds check because the sentinal value will keep us in bounds

		while(v < a[j-1]) {
			a[j] = a[j-1];
			--j;
		}

		a[j] = v;
	}

	for(int i = 0; i < SIZE; i++) {
		cout << a[i] << endl;
	}
*/

/*
Selection sort:

	const int SIZE = 100;
	int a[SIZE];

	for(int i = 0; i < SIZE; i++) {
		a[i] = rand();
	}

	int lo = 0;
	int hi = SIZE - 1;

	for(int i = lo; i < hi; ++i) { //Swaps only up to next to last element
		int min = i;
		for(int j = i + 1; j <= hi; ++j) {
			if (a[j] < a[min]) min = j;
		}

		swap(a[i], a[min]);
	}

	for(int i = 0; i < SIZE; i++) {
		cout << a[i] << endl;
	}
*/
	
	return 0;
}

void compexch(int &a, int &b) {
	if (b < a) {
		swap(b, a);
	}
}