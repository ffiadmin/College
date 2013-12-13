/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the KhetPiece class which is derived from tile and derives all of our Khet Pieces  
*/

#include "Tile.h"

#ifndef KHETPIECE_H
#define KHETPIECE_H

enum RESPONSE {UP, DOWN, LEFT, RIGHT, DESTROY, NOTHING};

class KhetPiece : public Tile
{
public:
	KhetPiece(Game* game, Graphics* graphics);

	void rotate(int dir); // 0 left (-90 degree) rotation, 1 right (90 degree) rotation
	virtual RESPONSE onCollision(int dir)=0; // what to do when piece is hit by laser
											// dir: 0 left, 1 up, 2 right, 3 down
	virtual char getName()=0;

	char getColor() {return color;}
	void setColor(char c) {color = c;}

private:
	char color; // r: red g: grey
};

class Invalid_rotation_dir_argument {};

#endif