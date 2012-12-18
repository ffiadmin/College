/* 
  Author:  Oliver Spryn 
  Course:  COMP 220, Computer Programming II 
  Date:    Nov 30 2012 
  Description:  This is the class definition file for the Ant class, which simply
                sets it apart from other organisms. 
*/

#include "Ant.h"

Ant::Ant() {
}

char Ant::shortType() {
	return Config::ANT_CHAR;
}

int Ant::type() {
	return Config::ANT;
}