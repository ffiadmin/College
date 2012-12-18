/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This is a custom exception to the be thrown
                in the case of a database connection failure.
*/ 

#include "BaseException.h"

class DatabaseConnectionException : public BaseException {
public:
	DatabaseConnectionException(string error);
};