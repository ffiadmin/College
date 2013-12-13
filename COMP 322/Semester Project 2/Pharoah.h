/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the Pharoah Piece class  
*/

#include "KhetPiece.h"

#ifndef PHAROAH_H
#define PHAROAH_H

class Pharoah : public KhetPiece
{
public:
	Pharoah(Game* game, Graphics* graphics, char color) : KhetPiece(game, graphics) {
		setColor(color);
		if(color == 'r')
			setGraphic(PHAROAH_RED, 2);
		else if(color == 'g')
			setGraphic(PHAROAH_GREY, 2);
	}

	RESPONSE onCollision(int dir) {return DESTROY;} // dir: 0 left, 1 up, 2 right, 3 down
	virtual char getName() {return 'H';}
private:

};

#endif