#include <iostream>
using namespace std;

const int MAX = 10;

template <class T>
struct Node {
	T data;
	Node<T> *next;
};

void swapStuff(Node<int> *first, Node<int> *last);

int main() {
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

//Swap the values
	Node<int> *prevareno;
	Node<int> *currentareno;
	swapStuff(first, last);

//Print out the values
	for (int i = 1; i <= MAX; ++i) {
		if (i == 1) {
			prevareno = NULL;
			currentareno = first;
		} else {
			prevareno = currentareno;
			currentareno = currentareno->next;
		}

		cout << currentareno->data << endl;
	}

	return 0;
}

void swapStuff(Node<int> *first, Node<int> *last) {
//Reorder the linked list
	bool incremented = false;
	Node<int> *prevareno;
	Node<int> *currentareno;

	for (int i = 1; i <= MAX; ++i) {
	//Set the current and previous linked list pointers
		if (!incremented) {
			if (i == 1) {
				prevareno = NULL;
				currentareno = first;
			} else {
				prevareno = currentareno;
				currentareno = currentareno->next;
			}
		} else {
			incremented = !incremented; //Haha, yesss.... (It sets incremented equal to false)
		}

	//Move the evens to the end of the linked list
		if (currentareno->data % 2 == 0) {
			last->next = currentareno;              //Point the last node to the current node
			prevareno->next = currentareno->next;   //Set the previous node equal to the next node
			currentareno->next = NULL;              //Now that the current pointer is last, don't have it point to anything
			last = currentareno;                    //Set the last node equal to the current node

			incremented = !incremented;             //Did it again! (It sets incremented equal to true)
			currentareno = prevareno->next;         //Set the new current equal to the next node, for the next iteration
		}
	}
}