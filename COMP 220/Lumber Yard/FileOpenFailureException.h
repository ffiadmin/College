/* 
  Author:  Oliver Spryn
  Course:  COMP 244, Database Management
  Date:    12 Nov 2012 
  Description:  This is a custom base exception which is thrown on file open error.
*/ 


#include "BaseException.h"

class FileOpenFailureException : public BaseException {
public:
	FileOpenFailureException(string error);
};