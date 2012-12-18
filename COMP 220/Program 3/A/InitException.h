/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This is a custom exception to the be thrown
                in the case of an illegal class initialization
*/ 


#include "baseexception.h"

class InitException : public BaseException {
public:
	InitException(string error);
};