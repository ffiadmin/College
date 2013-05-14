/*
Author:  Oliver Spryn
Course: COMP 222, Data Structures
Date: 7 March 2012
Description: This file implements the definition for the list-based stack class
*/

template <class T, int MaxSize>
Stack<T, MaxSize>::Stack() {
	this->head = 0;
	this->sizeR = 0;
};

template <class T, int MaxSize>
Stack<T, MaxSize>::~Stack() {
	this->flush();
};

template <class T, int MaxSize>
void Stack<T, MaxSize>::push(const T& item) {
	if (this->sizeR == MaxSize) {
		throw Overflow();
	} else {
		this->head = new Node(item, this->head);
		this->sizeR++;
	}
};

template <class T, int MaxSize>
T Stack<T, MaxSize>::pop() {
	if (this->sizeR - 1 == -1) {
		throw Underflow();
	} else {
		T item = this->head->item;
		Node *link = this->head->next;

		delete this->head;
		this->head = link;
		this->sizeR--;
		return item;
	}
};

template <class T, int MaxSize>
void Stack<T, MaxSize>::flush() {
	while(this->sizeR) {
		this->pop();
	}
}

template <class T, int MaxSize>
int Stack<T, MaxSize>::size() const {
	return this->sizeR;
}

template <class T, int MaxSize>
bool Stack<T, MaxSize>::empty() const {
	return this->sizeR == 0;
}