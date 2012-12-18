/* 
  Author:  Oliver Spryn 
  Course:  COMP 220, Computer Programming II 
  Date:    Nov 30 2012 
  Description:  This is the class definition file for the DoodleBug class, which simply
                sets it apart from other organisms. 
*/

#include "Organism.h"

class DoodleBug : public Organism {
public:
	DoodleBug();
	char shortType();
	int type();
};