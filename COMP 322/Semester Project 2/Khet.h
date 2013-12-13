/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the Khet class and is our main game engine  
*/

#ifndef KHET_H
#define KHET_H

#include "game.h"
#include "Grid.h"
#include "KhetParser.h"
#include "Laser.h"
#include "Tile.h"
#include "Explode.h"

struct ExplodeData {
	ExplodeData() {really = false; x = 0; y = 0;};
	bool really;
	int x;
	int y;
};

class Khet : public Game {
private : 
    Grid<KhetPiece, X, Y>* g;
	KhetParser<KhetPiece>* kp;
	Laser* l;
	Explode* explosion;
	ExplodeData ep;

    GAMESTATE gamestate;

	int step;
	char turn;
	char loser;
	vector<vector<KhetPiece*>>* grid;
	ClickData<KhetPiece> active;
	bool activeSelected;
    bool clickedThisFrame;
	bool displayed;

	Image start;
	Image numGrid;
    Image rules;
    Image pieceInfo;
	Image controls;
    
	TextureManager startTexture;
    TextureManager numGridTexture;
    TextureManager instructionsTexture;
    TextureManager piecesTexture;
	TextureManager controlsTexture;
public : 
	Khet();
	~Khet();

	void ai();
	void callback(ClickData<KhetPiece> d);
	void collisions();
	void initialize(HWND hwnd);
    void releaseAll();
    void render();
    void resetAll();
	void update();
    bool canSwap(int,int);
};

#endif