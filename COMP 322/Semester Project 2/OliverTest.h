/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the Oliver Test class and was used to test our program in early stages  
*/

#ifndef OLIVER_TEST_H
#define OLIVER_TEST_H

#include "game.h"
#include "Grid.h"
#include "KhetParser.h"
#include "Laser.h"
#include "Tile.h"

void callback(ClickData<Tile> t);

class OliverTest :	public Game {
private : 
	char dir;
	float fireDeg1, fireDeg2;
	Grid<Tile, 10, 8>* g;
	KhetParser<Tile>* kp;
	Laser* l;
	Laser* l2;
	Tile* t;
	Tile* t2;
	Tile* tiles[10][10];
    bool isTileSelected;

public : 
	OliverTest();
	~OliverTest();

	void ai();
	void collisions();
	void initialize(HWND hwnd);
    void releaseAll();
    void render();
    void resetAll();
	void update();
    friend void gameEvent(Tile*);
};

#endif