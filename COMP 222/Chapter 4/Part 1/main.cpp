#include <iostream>
using namespace std;

const int N = 8;

int main() {
	int **matrix;
	matrix = new int*[N];

	for(int i = 0; i < N; ++i) {
		matrix[i] = new int[N];

		for(int j = 0; j < N; ++j) {
			if (i == j) {
				matrix[i][j] = 1; //2-2 is connected
			} else {
				matrix[i][j] = 0;
			}
		}
	}

	int p, q;

	while (cin >> p >> q) {
		cout << p << " " << q << endl;

		matrix[p][q] = 1; //If 2-3, then
		matrix[q][p] = 1; //3-2
	}

	cout << endl;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << matrix[i][j];
		}

		cout << endl;
	}

	cout << endl;

	return 0;
}