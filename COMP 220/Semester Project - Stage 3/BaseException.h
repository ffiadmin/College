/* 
  Authors:  Oliver Spryn
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class is the base exception which all other custom exception classes will extend. 
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