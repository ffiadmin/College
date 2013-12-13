/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file implements the Anubis Piece class  
*/
#include "KhetPiece.h"

#ifndef ANUBIS_H
#define ANUBIS_H

class Anubis : public KhetPiece
{
public:
	Anubis(Game* game, Graphics* graphics, char color);
	RESPONSE onCollision(int dir); // dir: 0 left, 1 up, 2 right, 3 down
	virtual char getName() {return 'A';}
private:

};

#endif