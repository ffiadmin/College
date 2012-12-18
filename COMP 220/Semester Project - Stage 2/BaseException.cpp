/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         15 October 2012 
 * Description:  This this part of a custom exception type
                 which will be thrown in the case of 
				 specific errors
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

	out << "\a" << be.error << endl;

	SetConsoleTextAttribute(cHandle, 7);
	return out;
}