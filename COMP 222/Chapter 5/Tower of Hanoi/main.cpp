#include <iostream>
using namespace std;

const int N = 31;
int towers(int n, int from, int to, int spare);
int a[N];

int main() {
	for (int i = 0; i < N; ++i) {
		a[i] = -1;
	}

	int n = N, from = 1, to = 3, spare = 2, keep = towers(n, from, to, spare);
	cout << keep << endl;

	return 0;
}

int towers(int n, int from, int to, int spare) {
	int moves = 0;

//Base case
	if (n == 0) {
		return 0;
	}
	
	if (a[n-1] != -1) {
		moves += a[n-1];
	} else {
		moves += towers(n - 1, from, spare, to);
	}

	moves++;
	//if (n>15) cout << "Moving disk " << n << " to peg " << to << endl;

	if (a[n-1] != -1) {
		moves += a[n-1];
	} else {
		moves += towers(n - 1, spare, to, from);
	}

	a[n] = moves;
	return moves;
}