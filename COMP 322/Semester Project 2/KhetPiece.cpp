/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file implements the KhetPiece class
*   which derives all the pieces
*/

#include "KhetPiece.h"

KhetPiece::KhetPiece(Game* game, Graphics* graphics) : Tile(game, graphics) {
	this->active = true;
	this->setCollisionType(entityNS::BOX);
	RECT e = {-5, -5, 5, 5};
	this->setEdge(e);
}

void KhetPiece::rotate(int dir)
{
	if(dir == 1)
		orientation++;
	else if(dir == 0)
		orientation--;
	else
		throw Invalid_rotation_dir_argument();

	if(orientation < 0)
		orientation = 3;
	else if(orientation > 3)
		orientation = 0;

	setCurrentFrame(orientation);
}