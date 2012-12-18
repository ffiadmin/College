#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class T>
void sort(vector<T> &v);

int main() {
	vector<char> stuff;
	stuff.push_back('c');
	stuff.push_back('b');
	stuff.push_back('a');
	stuff.push_back('e');
	stuff.push_back('d');
	
	sort(stuff);

	for(int i = 0; i < stuff.size(); i++) {
		cout << stuff[i] << endl;
	}

	return 0;
}

template <class T>
void sort(vector<T> &v) {
	bool switchOccured = true;
	int size = v.size();
	T temp;

	while(switchOccured) {
		switchOccured = false;

		for (int i = size - 1; i >= 1; i--) {
			if (v[i] < v[i - 1]) {
				switchOccured = true;

				temp = v[i];
				v[i] = v[i - 1];
				v[i - 1] = temp;
			}
		}
	}
}