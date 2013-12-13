/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the Sphinx Piece class  
*/

#include "KhetPiece.h"

#ifndef SPHINX_H
#define SPHINX_H

class Sphinx : public KhetPiece
{
public:
	Sphinx(Game* game, Graphics* graphics, char color) : KhetPiece(game, graphics) {
		setColor(color);
		if(color == 'r')
			setGraphic(SPHINX_RED, 2);
		else if(color == 'g')
			setGraphic(SPHINX_GREY, 2);
	}
	RESPONSE onCollision(int dir) {return NOTHING;} // dir: 0 left, 1 up, 2 right, 3 down
	virtual char getName() {return 'X';}
private:

};

#endif