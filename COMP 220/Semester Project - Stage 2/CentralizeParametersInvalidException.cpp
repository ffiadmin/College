/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         15 October 2012 
 * Description:  This this part of a custom exception type
                 which will be thrown in the case of 
				 specific errors
*/ 


#include "CentralizeParametersInvalidException.h"

CentralizeParametersInvalidException::CentralizeParametersInvalidException(string error) : BaseException(error) {
	//This constructor simply calls the super constructor
}