/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This is a custom base exception which all other
                custom exception classes extend.
*/ 


#include <windows.h>

#include "BaseException.h"

using std::endl;

BaseException::BaseException(string error) {
	this->error = error;
}

ostream &operator<< (ostream &out, BaseException be) {
	HANDLE cHandle;
	cHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cHandle, 12);

	out << be.error << endl;

	SetConsoleTextAttribute(cHandle, 7);
	return out;
}