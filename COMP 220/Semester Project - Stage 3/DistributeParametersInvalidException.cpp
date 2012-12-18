/* 
  Authors:  Oliver Spryn
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class is the custom exception which will be thown if the 
	            distribute parameters function recieves invalid input. 
*/ 

#include "DistributeParametersInvalidException.h"

DistributeParametersInvalidException::DistributeParametersInvalidException(string error) : BaseException(error) {
	//This constructor simply calls the super constructor
}