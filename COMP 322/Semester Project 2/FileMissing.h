/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the filemissing error handling class  
*/

#include "BaseException.h"

class FileMissing : public BaseException {
public:
	FileMissing(string error);
};