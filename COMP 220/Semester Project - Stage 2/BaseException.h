/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         15 October 2012 
 * Description:  This this part of a custom exception type
                 which will be thrown in the case of 
				 specific errors
*/ 


#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <string>
#include <ostream>

using std::ostream;
using std::string;

class BaseException {
	friend ostream &operator<< (ostream &out, BaseException be);

public : 
	BaseException(string error);

private : 
	string error;
};

#endif