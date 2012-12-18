/* 
  Authors:  Dorian P. Yeager
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class contains various overloaded function for use on cursor information
				for the Doucment class. 
*/ 


#ifndef __CONTEXT_H
#define __CONTEXT_H

class Context {
public:
	int offset;
	Context(int offset=0): offset(offset) {}
	bool operator == (const Context &context) {
		return offset == context.offset;
	}
	bool operator < (const Context &context) {
		return offset < context.offset;
	}
	bool operator > (const Context &context) {
		return offset > context.offset;
	}
	bool operator <= (const Context &context) {
		return offset <= context.offset;
	}
	bool operator >= (const Context &context) {
		return offset >= context.offset;
	}
	bool operator != (const Context &context) {
		return offset != context.offset;
	}
};

#endif
