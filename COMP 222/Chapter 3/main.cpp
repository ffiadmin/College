#include <iostream>
using namespace std;

/*struct Item {
	Item() { value = 0; }
	Item(int v) { value = v; }
	int value; //4 bytes
};

struct Node {
	Node(const Item &d, Node *n) { data = d; next = n; }
	Item data;
	Node *next; //4 bytes
};*/

class Node {
	public : 
		Node(int d, Node *n):data(d), next(n) { } //Template
		int data; //Template
		Node *next; //Passes responsiblity of BIG THREE to Circ_list
};

class Circ_list {
	public : 
		//BIG THREE
		Circ_list();
		bool empty();
		void insert(int x); //Template
		void advance(int links = 1);
		void remove();
		bool single();

		int &get_current(); //Template
		
	private : 
		Node *current;
};

int main() {
	/*double a[100];
	double *p = a;

	p = &a[1];

	cout << a << " " << p << endl; //4 apart
	cout << p - a << endl; //1 apart

	double *i;
	int count;

	for (i = a, count = 0; i - a < 100; i++, count++) {
		*i = count;
	}

	for (int i = 0; i < 100; i++) {
		cout << a[i] << endl;
	}*/
	/*
	Sieve problem
	int n = 0;

	cout << "Enter N: ";
	cin >> n;

	//make sure it is positive, or whatever
	n++;

	bool *p = new bool[n];

	for(int i = 2; i < n; i++) { //look at the notes, say 2-19 values are initialized
		p[i] = true;
	}

	for (int i = 2; i * i <= n; i++) { //set primes = false
		if(p[i]) {
			for(int j = i; j*i < n; j++) {
				p[i*j] = false;
			}

			//for (int j = i * i; j < n; j += i) { //if i = 2, skip it so we go to 4
			//	p[j] = false;
			//}
		}
	}

	for(int i = 2; i < n; i++) {
		if (p[i]) {
			cout << i << "\t";
		}
	}*/
	/*
//Solve the Joesphus problem
	const int N = 9001;
	const int M = 5; //Kill every 5th person
	Node *p;

	//Calls constructor, returns a value of the object itself
	//Created on the stack
	//Simply an unnamed location in memory
	//Has the scope of the statement
	p = new Node(Item(1), NULL); //8 bytes
	p->next = p; //Circular linked list

//Insert some nodes
	Node *x = p;

	for(int i = 2; i <= N; i ++) {
		x->next = new Node(Item(i), p);
		x = x->next;
	}

//Start killing people
	while(x != x->next) {
		for(int i = 1; i < M; i++) {
			x = x->next;
		}

		Node *deleteMe = x->next;
		x->next = x->next->next;
		delete deleteMe;
	}

	cout << x->data.value << " lives!" << endl;*/

	Circ_list joe;
	const int N = 9;
	const int M = 5;

	for(int i = 1; i < N; i++) {
		joe.insert(i);
		joe.advance();
	}

	while(!joe.empty() && !joe.single()) {
		joe.advance(M - 1);
		joe.remove();
	}

	cout << joe.get_current() << endl;

	return 0;
}

Circ_list::Circ_list() {
	current = NULL; //Empty list
}

bool Circ_list::empty() {
	return current == NULL;
}

void Circ_list::insert(int x) {
	Node *temp;

	if (current == NULL) {
		temp = new Node(x, NULL);
		temp->next = temp;
		current = temp;
	} else {
		temp = new Node(x, current->next);
		current->next = temp;
	}
}

void Circ_list::advance(int links) {
	if (!empty()) {
		for(int i = 0; i < links; i++) {
			current = current->next;
		}
	}
}

void Circ_list::remove() {
	if (!empty()) {
		Node *temp = current->next;

		if (current == current->next) {
			delete current;
			current = NULL;
		} else {
			current = current->next->next;
			delete temp;
		}
	}
}

bool Circ_list::single() {
	if (empty()) {
		return false;
	} else {
		return current == current->next;
	}
}

int &Circ_list::get_current() {
	if (empty()) {
		throw 42;
	} else {
		return current->data; //ALlows the user to mess with the data
	}
}