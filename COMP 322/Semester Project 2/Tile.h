/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the tile class  
*/

#ifndef TILE_H
#define TILE_H
#define WIN32_LEAN_AND_MEAN

#include <string>

#include "entity.h"
#include "game.h"
#include "gameError.h"
#include "graphics.h"
#include "InvalidOrientation.h"
#include "textureManager.h"

using std::string;

namespace tileNS {
	const char GRAPHIC[] = "pictures\\tile.png";
	const int  HEIGHT    = 64;
	const int  WIDTH     = 64;
}

class Tile : public Entity {
private : 
	int direction;
	Game* game;
	Graphics* graphics;
	TextureManager tm;

	string graphic;
	int numCols;
	D3DXVECTOR2 intersectDepthVector(Entity &ent);

protected : 
	int orientation; //current frame: 0 left, 1 up, 2 right, 3 down
	
public : 
	Tile(Game* game, Graphics* graphics);
	virtual ~Tile();

	virtual bool collidesWith(Entity &ent, D3DXVECTOR2 &collisionVector);
	virtual bool collidesWithBottom(Entity &ent, D3DXVECTOR2 &collisionVector);
	virtual bool collidesWithLeft(Entity &ent, D3DXVECTOR2 &collisionVector);
	virtual bool collidesWithRight(Entity &ent, D3DXVECTOR2 &collisionVector);
	virtual bool collidesWithTop(Entity &ent, D3DXVECTOR2 &collisionVector);
	int getDirection();
	int getOrientation();
	virtual void initialize();
	void setGraphic(string graphic, int numCols);
	void setOrientation(int orientation);
};

#endif