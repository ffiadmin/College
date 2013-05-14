#include <iostream>
using namespace std;

int *value;
int *W;
int stop;
int **DP;

int method(int i, int weight);

int main() {
	int n;
	cin >> n;

	for (int x = 0; x < n; x++) {
		int len;
		cin >> len;
		stop = len;

		value = new int[len];
		W = new int[len];

		for (int i = 0; i < len; i++) {
			cin >> value[i];
			cin >> W[i];

			int g;
			cin >> g;
			long sum = 0;

			DP = new int*[len+1];
			for(int i = 0; i < len + 1; i++) {
				DP[i] = new int[31];
			}

			for(int i = 0; i < len + 1; i++) {
				for(int j = 0; j < 31; j++) {
					DP[i][j] = -1;
				}
			}
		}
	}

	return 0;
}

int method(int i, int weight) {
	if (weight == 0 || i == stop) {
		return 0;
	} else {
		if (DP[i][weight] != -1)
			return DP[i][weight]; //remember the solutions to sub-problems
		if(weight <= W[i]) {// it is possible that I could carry this object
			return DP[i][weight] = //remembers the solutions to a sub-problem I've seen before
				max(method(i + 1, weight), //either it is better to leave out the ith item
				method(i + 1, weight - W[i]) + value[i]);
		} else 
			return method(i + 1, weight); //or maybe you can't even hold the item
	}
}

/*
Solution above:

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout;
	fout.open("output.txt");

	int T, N, *P, *W, G, *MW, *MP;
	int *MaxFamily;
	cin >> T;

	MaxFamily = new int[T];

	for (int i = 0; i < T; ++i) {
		cin >> N;
		P = new int[N], W = new int[N];

	//Read in the prices and weights
		for (int j = 0 ; j < N; ++j) {
			cin >> P[j];
			cin >> W[j];
		}

	//Read in the maximum weight each person can carry
		cin >> G;
		MW = new int[G], MP = new int[G];

		for (int k = 0; k < G; ++k) {
			//Put long code I can't figure out here
		}

	//Add their max prices together
		MaxFamily[i] = 0;

		for(int l = 0; l < G; ++l) {
			MaxFamily[i] += MP[l];
		}

	//Write out the results
		fout << MaxFamily[i] << endl;

		delete [] P, W, MW, MP;
	}

	delete [] MaxFamily;
	fout.close();

	return 0;
}*/