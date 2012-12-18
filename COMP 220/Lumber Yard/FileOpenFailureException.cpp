/* 
  Author:  Oliver Spryn
  Course:  COMP 244, Database Management
  Date:    12 Nov 2012 
  Description:  This is a custom base exception which is thrown on file open error.
*/ 


#include "FileOpenFailureException.h"

FileOpenFailureException::FileOpenFailureException(string error) : BaseException(error) {
	//This is the job of the super constructor
}