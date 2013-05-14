#include <iostream>
using namespace std;

//We will see 10000 different nodes, max
const int N = 10000;

void quick_find();
void quick_union();
void weighted_quick_union();
void weighted_quick_union_with_path_compression_by_halving();

int main() {
	quick_union();

	return 0;
}

void quick_find() {
	int id[N];

	for (int i = 0; i < N; i++) {
		id[i] = i;
	}

	int p, q;

//Goes until fail state
	while(cin >> p >> q) {
		//Find if the values are connected and union them if they are
		//Union them if they are
		//Output the pair

	//Find
		if (id[p] == id[q]) {
			continue;
	//Union
		} else {
			int t = id[p];

			for (int i = 0; i < N; i++) {
				if (id[i] == t) {
					id[i] = id[q];
				}
			}
		}

		cout << p << " " << q << endl;
	}
}

void quick_union() {
	int id[N];
	int i, j, k;

	for (i = 0; i < N; i++) {
		id[i] = i;
	}

	int p, q;

//Goes until fail state
	while(cin >> p >> q) {
	//Find is more complicated
		for (j = p; j != id[j]; j = id[j]); //loop until j is the representative of p.
		for (k = q; k != id[k]; k = id[k]); //loop until k is the representative of q.

		if (j == k) {
			continue;
	//Union
		} else {
			id[j] = k;
		}

		cout << p << " " << q << endl;
	}
}

void weighted_quick_union() {
	int id[N];
	int size[N];
	int i, j, k;

	for (i = 0; i < N; i++) {
		id[i] = i;
		size[i] = 1;
	}

	int p, q;

//Goes until fail state
	while(cin >> p >> q) {
	//Find is more complicated
		//j = p;
		//
		//while(id[j] != j) { //loop until j is the representative of p.
		//	j = id[j];
		//}

		//OR
		for (j = p; j != id[j]; j = id[j]); //loop until j is the representative of p.
		for (k = q; k != id[k]; k = id[k]); //loop until k is the representative of q.

		if (j == k) {
			continue;
	//Union
		} else {
			if (size[j] > size[k])  {
				id[k] = j;
				size[j] += size[k]; //See notes as to why we did size[j] not size[k]
			} else {
				id[j] = k;
				size[k] += size[j];
			}
		}

		cout << p << " " << q << endl;
	}
}

void weighted_quick_union_with_path_compression_by_halving() {
	int id[N];
	int size[N];
	int i, j, k;

	for (i = 0; i < N; i++) {
		id[i] = i;
		size[i] = 1;
	}

	int p, q;

//Goes until fail state
	while(cin >> p >> q) {
	//Find is more complicated
		for (j = p; j != id[j]; j = id[j]) { //loop until j is the representative of p.
			id[j] = id[id[j]]; //Point one higher
		} 
		for (k = q; k != id[k]; k = id[k]); //loop until k is the representative of q.

		if (j == k) {
			continue;
	//Union
		} else {
			if (size[j] > size[k])  {
				id[k] = j;
				size[j] += size[k]; //See notes as to why we did size[j] not size[k]
			} else {
				id[j] = k;
				size[k] += size[j];
			}
		}

		cout << p << " " << q << endl;
	}
}