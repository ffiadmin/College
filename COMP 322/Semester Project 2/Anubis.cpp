/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file implements the Anubis Piece class  
*/

#include "Anubis.h"

Anubis::Anubis(Game* game, Graphics* graphics, char color) : KhetPiece(game, graphics)
{
	setColor(color);
	if(color == 'r')
		setGraphic(ANUBIS_RED, 2);
	else if(color == 'g')
		setGraphic(ANUBIS_GREY, 2);
}

RESPONSE Anubis::onCollision(int dir)
{
	// dir: 0 left, 1 up, 2 right, 3 down
	if(Anubis::getOrientation() == dir)
		return NOTHING;
	else
		return DESTROY;
}