#include <iostream>
using namespace std;

const int MAX = 10;

struct Node {
	int data;
	Node *next;
};

int main() {
	Node *first = new Node();
	Node *prev;

	for (int i = 1; i <= MAX; ++i) {
	//No pointer on first run
		if (i == 1) {
			first->data = i;
			first->next = NULL;

			prev = first;
		} else if (i != MAX) {
			Node *list = new Node();
			list->data = i;
			list->next = NULL;
			prev->next = list;

			prev = list;
		} else {
			Node *list = new Node();
			list->data = i;
			list->next = NULL;
			prev->next = list;
		}
	}

	for (int i = 1; i <= Math.ceil(MAX / 2); ++i) {

	}

	cout << first->next->data;
}