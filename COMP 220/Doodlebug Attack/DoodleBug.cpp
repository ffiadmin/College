/* 
  Author:  Oliver Spryn 
  Course:  COMP 220, Computer Programming II 
  Date:    Nov 30 2012 
  Description:  This is the class definition file for the DoodleBug class, which simply
                sets it apart from other organisms. 
*/

#include "DoodleBug.h"

DoodleBug::DoodleBug() {
}

char DoodleBug::shortType() {
	return Config::DOOBLEBUG_CHAR;
}

int DoodleBug::type() {
	return Config::DOOBLEBUG;
}