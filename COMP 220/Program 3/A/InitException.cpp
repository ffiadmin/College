/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This is a custom exception to the be thrown
                in the case of an illegal class initialization
*/ 

#include "InitException.h"

InitException::InitException(string error) : BaseException(error) {
	//The super constructor will handle this
}