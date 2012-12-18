/* 
  Author:  Oliver Spryn 
  Course:  COMP 220, Computer Programming II 
  Date:    Nov 30 2012 
  Description:  This is the class definition file for the Organism base class for the Ant and DoodleBug classes. 
*/

#ifndef ORGANISM_H
#define ORGANISM_H

#include <algorithm>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>

#include "Config.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Organism {
public : 
	Organism();
	int movesSinceEating;
	int movesSinceBreeding;

	int breed(int you);
	int move(int you);
	virtual char shortType();
	virtual int type();

private : 
	int dirRand();
};

#endif