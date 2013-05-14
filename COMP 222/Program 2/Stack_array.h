/*
Author:  Oliver Spryn
Course: COMP 222, Data Structures
Date: 7 March 2012
Description: This file implements the definition for the array-based stack class
*/

template <class T, int MaxSize>
Stack<T, MaxSize>::Stack() {
	this->stack = new T[MaxSize];
	this->sizeR = 0;
};

template <class T, int MaxSize>
Stack<T, MaxSize>::~Stack() {
	delete [] this->stack;
};

template <class T, int MaxSize>
void Stack<T, MaxSize>::push(const T& item) {
	if (this->sizeR == MaxSize) {
		throw Overflow();
	} else {
		this->stack[this->sizeR++] = item;
	}
};

template <class T, int MaxSize>
T Stack<T, MaxSize>::pop() {
	if (this->empty()) {
		throw Underflow();
	} else {
		return this->stack[--this->sizeR];
	}
};

template <class T, int MaxSize>
void Stack<T, MaxSize>::flush() {
	delete [] this->stack;
	this->stack = new T[MaxSize];
	this->sizeR = 0;
}

template <class T, int MaxSize>
int Stack<T, MaxSize>::size() const {
	return this->sizeR;
}

template <class T, int MaxSize>
bool Stack<T, MaxSize>::empty() const {
	return this->sizeR == 0;
}