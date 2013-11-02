// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Move spacejpo with arrow keys.
// Chapter 5 spacewar.cpp v1.0
// This class is the core of the game

#include "spaceWar.h"

//=============================================================================
// Constructor
//=============================================================================
Spacewar::Spacewar()
{}

//=============================================================================
// Destructor
//=============================================================================
Spacewar::~Spacewar()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Spacewar::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError
    if (!jpoTexture.initialize(graphics,JPO_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing jpo texture"));

    if (!jpo.initialize(graphics,JPO_WIDTH, JPO_HEIGHT, JPO_COLS, &jpoTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing jpo"));
    jpo.setX(GAME_WIDTH/4);                    // start above and left of planet
    jpo.setY(GAME_HEIGHT/4);
    jpo.setFrames(JPO_LOOKING_RIGHT_START, JPO_LOOKING_RIGHT_END);   // animation frames
    jpo.setCurrentFrame(JPO_LOOKING_RIGHT_START);     // starting frame
    jpo.setFrameDelay(JPO_ANIMATION_DELAY);

	lastDirection = right;
	keyDownLastFrame = false;
	keyDownThisFrame = false;
    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Spacewar::update()
{

	if(input->isKeyDown(JPO_RIGHT_KEY))            // if move right
	{				jpo.setFrames(JPO_WALKING_RIGHT_START, JPO_WALKING_RIGHT_END);
	//jpo.setCurrentFrame(JPO_WALKING_RIGHT_START);
	jpo.setX(jpo.getX() + frameTime * JPO_SPEED);
	this->lastKey = 'R';
	if (jpo.getX() > GAME_WIDTH)               // if off screen right
		jpo.setX((float)-jpo.getWidth());     // position off screen left
	}
	if(!input->isKeyDown(JPO_RIGHT_KEY) && this->lastKey == 'R')            // if look right
	{				jpo.setFrames(JPO_LOOKING_RIGHT_START, JPO_LOOKING_RIGHT_END);
	jpo.setCurrentFrame(JPO_LOOKING_RIGHT_START);
	}
	if(input->isKeyDown(JPO_LEFT_KEY))             // if move left
	{
		jpo.setCurrentFrame(JPO_LOOKING_LEFT_START);
		jpo.setFrames(JPO_LOOKING_LEFT_START, JPO_LOOKING_LEFT_END);
		jpo.setX(jpo.getX() - frameTime * JPO_SPEED);
		this->lastKey = 'L';
		if (jpo.getX() < -jpo.getWidth())         // if off screen left
			jpo.setX((float)GAME_WIDTH);           // position off screen right
	}

	jpo.update(frameTime);
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Spacewar::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Spacewar::collisions()
{}

//=============================================================================
// Render game items
//=============================================================================
void Spacewar::render()
{
    graphics->spriteBegin();                // begin drawing sprites
    jpo.draw();                            // add the spacejpo to the scene
    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Spacewar::releaseAll()
{
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Spacewar::resetAll()
{
    Game::resetAll();
    return;
}
