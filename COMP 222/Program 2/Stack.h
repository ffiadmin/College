/*
Author:  Oliver Spryn
Course: COMP 222, Data Structures
Date: 7 March 2012
Description: This file contains the declaration for the stack class
*/

#ifndef Stack_h
#define Stack_h

// Uncomment the following macro definition to use
// array-based Stack ADT
#define USE_ARRAY

template<class T, int MaxSize>
class Stack
{
public:
  class Overflow  {};
  class Underflow {};

  Stack();
  ~Stack();

  void push(const T& item);
  T    pop();

  void flush();
  int  size() const;
  bool empty() const;

private:
	int sizeR;

#ifdef USE_ARRAY
  T *stack;
#else
  struct Node {
	T item;
    Node *next;

	Node(T x, Node *t) {
		this->item = x;
		this->next = t;
	}
  };

  Node *head;
#endif
};

#ifdef USE_ARRAY
#  include "Stack_array.h"
#else
#  include "Stack_list.h"
#endif

#endif // Stack_h