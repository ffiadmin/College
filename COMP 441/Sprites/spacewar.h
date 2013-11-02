// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 5 spacewar.h v1.0

#ifndef _SPACEWAR_H             // Prevent multiple definitions if this 
#define _SPACEWAR_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"

struct position {
	float x;
	float y;
	position() : x(0), y(0) {}
};

struct velocity {
	float x;
	float y;
	velocity() : x(0), y(0) {}
};

//=============================================================================
// This class is the core of the game
//=============================================================================
class Spacewar : public Game
{
private:
    // game items
    TextureManager nebulaTexture;   // nebula texture
    TextureManager planetTexture;   // planet texture
	TextureManager horseTexture;    // horse texture
    Image   planet;                 // planet image
    Image   nebula;                 // nebula image
	Image   horse;                  // horse image

	position pos;
	velocity vel;
	int directionX;
	int directionY;

public:
    // Constructor
    Spacewar();

    // Destructor
    virtual ~Spacewar();

    // Initialize the game
    void initialize(HWND hwnd);
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
};

#endif
