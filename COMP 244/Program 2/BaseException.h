/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This is a custom base exception which all other
                custom exception classes extend.
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