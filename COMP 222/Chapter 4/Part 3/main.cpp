#include <iostream>
using namespace std;

template <class T>
class Push_down_stack { //Use the top of the stack 
public : 
	Push_down_stack(int size);
	bool empty() const;
	void push(T item);
	T pop();
};

template <class T>
class FIFO_queue {
public :
	FIFO_queue(int size);
	bool empty() const;
	put(T item);
	T get();
};

int main() {

	return 0;
}