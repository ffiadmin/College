/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file implements the exception class from which all other exceptions are derived  
*/

#include "BaseException.h"

class InvalidOrientation : public BaseException {
public:
	InvalidOrientation(string error);
};