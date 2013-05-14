#include <iostream>
using namespace std;

int cnt = 0;
int DP[50];

int gcd(int m, int n) {
	if (n == 0) return m;
	return gcd(n, m%n);
}

int F(int n) {
	cnt++;
	if (n == 0 || n == 1) {
		return 1;
	} else {
		if (DP[n] != -1) {
			return DP[n];
		}

		return DP[n] = F(n - 1) + F(n - 2);
	}
}

//Look at book for terrible solution to knapsack problem

int main() {
	for (int i = 0; i < 50; i++) {
		DP[i] = -1;
	}

	cout << F(36) << endl;
	cout << cnt << endl;

	return 0;
}