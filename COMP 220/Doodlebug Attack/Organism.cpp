/* 
  Author:  Oliver Spryn 
  Course:  COMP 220, Computer Programming II 
  Date:    Nov 30 2012 
  Description:  This is the class definition file for the Organism base class for the Ant and DoodleBug classes. 
*/

#include "Organism.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

Organism::Organism() {
	this->movesSinceEating = 0;
}

int Organism::move(int you) {
	this->movesSinceEating++;
	this->movesSinceBreeding++;

	int toLocation = this->dirRand();
	int locIndex = 0;
	int youz = you;
	
	switch(toLocation) {
	//Move up
		case 1 : 
			locIndex = youz - 20;
			break;

	//Move left
		case 2 : 
			locIndex = youz-1;
			break;

	//Move right
		case 3 : 
			locIndex = youz+1;
			break;

	//Move down
		case 4 : 
			locIndex = youz + 20;
			break;

		default : 
			cout << "WHERE DID A " << toLocation << " COME FROM?!?!"
				 << endl;
	}
	
//Don't move off the area!
	if (locIndex < 0 && locIndex >= 400) {
		locIndex = you;
	}
	
	return locIndex;
}

int Organism::breed(int you) {
	this->movesSinceBreeding = 0;

	int toLocation = this->dirRand();
	int locIndex = 0;
	int youz = you;
	
	switch(toLocation) {
	//Move up
		case 1 : 
			locIndex = youz - 20;
			break;

	//Move left
		case 2 : 
			locIndex = youz-1;
			break;

	//Move right
		case 3 : 
			locIndex = youz+1;
			break;

	//Move down
		case 4 : 
			locIndex = youz + 20;
			break;

		default : 
			cout << "WHERE DID A " << toLocation << " COME FROM?!?!"
				 << endl;
	}
	
//Don't move off the area!
	if (locIndex < 0 && locIndex >= 400) {
		locIndex = you;
	}
	
	return locIndex;
}

char Organism::shortType() {
	return Config::ORGANISM_CHAR;
}

int Organism::type() {
	return Config::ORGANISM;
}

int Organism::dirRand() {
   return 1 + static_cast<int>( rand()/static_cast<double>(RAND_MAX) * 4 );
}