#include <iostream>
using namespace std;

const int MAX = 100;
int countR = 0;

template <class T>
struct Node {
	T data;
	Node<T> *next;
};

int factorial(int N);
int puzzle(int N);
int countNodes(Node<int> *N);
void visitify(Node<int>* N) {cout << N->data << endl;}
void traverse(Node<int> *in, void visit(Node<int> *));
int maxVal(const int a[], int l, int r);

int main() {
	//cout << factorial(4) << endl;
	//puzzle(83);

	Node<int> *first = new Node<int>();
	Node<int> *prev;
	Node<int> *last;

//Initialize the linked list
	for (int i = 1; i <= MAX; ++i) {
		if (i == 1) {
			first->data = i;
			first->next = NULL;

			prev = first;
		} else if (i != MAX) {
			Node<int> *list = new Node<int>();
			list->data = i;
			list->next = NULL;
			prev->next = list;

			prev = list;
		} else {
			Node<int> *list = new Node<int>();
			list->data = i;
			list->next = NULL;
			prev->next = list;

			last = list;
		}
	}

	//cout << countNodes(first) << endl;
	//traverse(first, visitify);

	int a[100] = {0, 0, 42};
	int maxn = a[0];

	for (int i = 0; i < 100; ++i) {
		if (a[i] > maxn) {
			maxn = a[i];
		}
	}

	cout << maxn << endl;

	cout << maxVal(a, 0, 99) << endl;
	cout << countR << endl;

	return 0;
}

int factorial(int N) { //Tail recursion
	if (N == 1) {
		return 1;
	}

	return N * factorial(N - 1);

//Iterative factorial solution
	//int answer = 1;
	//for(int i = N; i > 1; --i) {
	//	answer *= i;
	//}
}

//Does the always terminate?
int puzzle(int n) { //Problem size does not get smaller for each call
	cout << "Puzzle for: " << n << endl;

	if (n == 1) {
		return 1;
	}

	if (n % 2 == 0)  {
		return puzzle(n/2);
	} else {
		return puzzle(3*n + 1);
	}
}

int countNodes(Node<int> *N) { //Tail recursion
	if (N->next == NULL) {
		return 1;
	}

	return 1 + countNodes(N->next);
}

void traverse(Node<int> *in, void visit(Node<int> *)) {
	if (in == NULL) {
		return;
	}

	visit(in);
	traverse(in->next, visit);
	//visit(in); // will print out the numbers backwords
	//If visit is at the end, it is not tail recursion
}

//No loops, constant time
//Linear performance
//Two parts that we divide sum up to the whole
int maxVal(const int a[], int l, int r) {
	if (l == r) {
		return a[l];
	}

	int m = (l+r)/2;
	int u = maxVal(a, l, m);
	int v = maxVal(a, m+1, r);
	countR = countR++;

	if (u > v) {
		return u;
	} else {
		return v;
	}
}