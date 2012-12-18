/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         15 October 2012 
 * Description:  This this part of a custom exception type
                 which will be thrown in the case of 
				 specific errors
*/ 


#include "baseexception.h"

class TextDisplayConfigurationException : public BaseException {
public:
	TextDisplayConfigurationException(string error);
};