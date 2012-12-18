/* 
  Author:  Oliver Spryn
  Course:  COMP 244, Database Management
  Date:    12 Nov 2012 
  Description:  This is a custom base exception which all other
                custom exception classes extend.
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