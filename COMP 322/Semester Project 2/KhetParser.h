/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the KhetParser class which derives GridParser for our application  
*/

#ifndef KHET_PARSER_H
#define KHET_PARSER_H

#include "Anubis.h"
#include "GridParser.h"
#include "Pharoah.h"
#include "Pyramid.h"
#include "Scarab.h"
#include "Sphinx.h"
#include "Tile.h"

template <class T>
class KhetParser : public GridParser<T> {
public : 
	KhetParser(string file) : GridParser(file) { }

	virtual T* configureTypes(char type, Game* game, Graphics* graphics) {
		T* returnVal;

		switch(type) {
			case 'A' : 
				returnVal = new Anubis(game, graphics, 'g');
				break;
			case 'a' : 
				returnVal = new Anubis(game, graphics, 'r');
				break;
			case 'H' : 
				returnVal = new Pharoah(game, graphics, 'g');
				break;
			case 'h' : 
				returnVal = new Pharoah(game, graphics, 'r');
				break;
			case 'P' : 
				returnVal = new Pyramid(game, graphics, 'g');
				break;
			case 'p' : 
				returnVal = new Pyramid(game, graphics, 'r');
				break;
			case 'S' : 
				returnVal = new Scarab(game, graphics, 'g');
				break;
			case 's' : 
				returnVal = new Scarab(game, graphics, 'r');
				break;
			case 'X' : 
				returnVal = new Sphinx(game, graphics, 'g');
				break;
			case 'x' : 
				returnVal = new Sphinx(game, graphics, 'r');
				break;
			default : 
				returnVal = new Anubis(game, graphics, 'g');
				returnVal->setActive(false);
				returnVal->setVisible(false);
				break;
		}

		return returnVal;
	}
};

#endif