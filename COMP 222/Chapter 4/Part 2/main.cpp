#include <iostream>
using namespace std;

const int N = 8;

struct Node {
	Node() {}
	Node(int v, Node *n) : v(v), next(n) {}

	int v;
	Node *next;
};

int main() {

	Node **a_list = new Node*[N];
	for (int i = 0; i < N; ++i) {
		a_list[i] = NULL;
	}

	int p, q;

	while (cin >> p >> q) {
		cout << p << " " << q << endl;
		Node *temp = new Node(p, a_list[q]);
		a_list[q] = temp;
		temp = new Node(q, a_list[p]);
		a_list[p] = temp;
	}

	cout << endl;

	for (int i = 0; i < N; ++i) {
		Node *temp = a_list[i];

		while (temp != NULL) {
			cout << temp->v << ", ";
			temp = temp->next;
		}

		cout << endl;
	}

	cout << endl;

	return 0;
}