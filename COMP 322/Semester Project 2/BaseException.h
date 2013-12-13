/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the BaseException class which all error handling classes are derived. 
*/

#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>
#include <ostream>

using std::exception;
using std::ostream;
using std::string;

class BaseException : public exception {
	friend ostream &operator<< (ostream &out, BaseException be);

public : 
	BaseException(string error);

private : 
	string error;
};

#endif