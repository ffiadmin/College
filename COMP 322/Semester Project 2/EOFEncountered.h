/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the EOFEncountered error handling class  
*/

#include "BaseException.h"

class EOFEncountered : public BaseException {
public:
	EOFEncountered(string error);
};