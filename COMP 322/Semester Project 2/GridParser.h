/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the grid parser class and sets up the grid according to an input file  
*/

#ifndef GRID_PARSER_H
#define GRID_PARSER_H

#include <fstream>
#include <string>

#include "EOFEncountered.h"
#include "FileMissing.h"
#include "game.h"
#include "graphics.h"

using std::ifstream;
using std::string;

template <class T>
class GridParser {
protected : 
	char current;
	ifstream fin;

public : 
	GridParser(string file) throw(FileMissing) : fin(file) {
		if (!this->fin.is_open()) {
			throw FileMissing("The text file is missing");
		}
	}

	int configureDir() throw(EOFEncountered) {
		char awesome = this->fin.get();
		int retVal;

	//Good, this is a nice character
		if (awesome != '\n' && !this->fin.eof()) {
			if (awesome == ' ') {
				return 0;
			} else {
				retVal = awesome - '0';
				return retVal;
			}
		}

	//Wait, end of line character
		if (awesome == '\n' && !this->fin.eof()) {
			awesome = this->fin.get();

		//Good, we are just wrapping onto a new line
				if (awesome != '\n') {
					if (awesome == ' ') {
					return 0;
				} else {
					retVal = awesome - '0';
					return retVal;
				}
			}
		}

	//We either hit an EOF or are going into a new section
		//throw EOFEncountered("The end of the file was reached or the parser is moving onto another section");
	}

	virtual T* configureTypes(char type, Game* game, Graphics* graphics) = 0;

	T* next(Game* game, Graphics* graphics) throw(EOFEncountered) {
		char awesome = this->fin.get();

	//Good, this is a nice character
		if (awesome != '\n' && !this->fin.eof()) {
			return this->configureTypes(awesome, game, graphics);
		}

	//Wait, end of line character
		if (awesome == '\n' && !this->fin.eof()) {
			awesome = this->fin.get();

		//Good, we are just wrapping onto a new line
			if (awesome != '\n') {
				return this->configureTypes(awesome, game, graphics);
			}
		}

	//We either hit an EOF or are going into a new section
		//throw EOFEncountered("The end of the file was reached or the parser is moving onto another section");
	}
};

#endif