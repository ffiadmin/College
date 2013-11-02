// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw planet with transparency
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

    // nebula texture
    if (!nebulaTexture.initialize(graphics,NEBULA_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula texture"));

    // planet texture
    if (!planetTexture.initialize(graphics,PLANET_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing planet texture"));

	// horse texture
    if (!horseTexture.initialize(graphics,HORSE_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing horse texture"));

    // nebula
    if (!nebula.initialize(graphics,0,0,0,&nebulaTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));


    // planet
    if (!planet.initialize(graphics,0,0,0,&planetTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing planet"));

	// horse
    if (!horse.initialize(graphics,0,0,0,&horseTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing horse"));

    // place planet in center of screen
    planet.setX(GAME_WIDTH*0.5f  - planet.getWidth()*0.5f);
    planet.setY(GAME_HEIGHT*0.5f - planet.getHeight()*0.5f);

	horse.setScale(0.5);
	horse.setX(GAME_WIDTH*0.5f - horse.getWidth()*0.5*0.5f);
    horse.setY(GAME_HEIGHT*0.5f - horse.getHeight()*0.5*0.5f);

	pos.x = horse.getX();
	pos.y = horse.getY();

	vel.x = 60;
	vel.y = 60;

	directionX = 0;
	directionY = 0;

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Spacewar::update()
{
	/*pos.x += vel.x * frameTime;
	pos.y += vel.y * frameTime;

	if (pos.x + horse.getWidth() * horse.getScale() > GAME_WIDTH || pos.x < 0) {
		vel.x *= -1;
		pos.x += vel.x * frameTime;
	}

	if (pos.y + horse.getHeight() * horse.getScale() > GAME_HEIGHT || pos.y < 0) {
		vel.y *= -1;
		pos.y += vel.y * frameTime;
	}*/

	/*if (input->isKeyDown(VK_LEFT))
		directionX--;
	if (input->isKeyDown(VK_RIGHT))
		directionX++;
	if (input->isKeyDown(VK_UP))
		directionY--;
	if (input->isKeyDown(VK_DOWN))
		directionY++;

	if (pos.x + horse.getWidth() * horse.getScale() > GAME_WIDTH || pos.x < 0)
		directionX = 0;

	if (pos.y + horse.getHeight() * horse.getScale() > GAME_HEIGHT || pos.y < 0)
		directionY = 0;

	pos.x = directionX * frameTime;
	pos.y = directionY * frameTime;*/

	pos.x += vel.x * frameTime;
	pos.y += vel.y * frameTime;

	if (pos.x + horse.getWidth() * horse.getScale() > GAME_WIDTH || pos.x < 0) {
		vel.x *= -1;
		pos.x += vel.x * frameTime;
	}

	if (pos.y + horse.getHeight() * horse.getScale() > GAME_HEIGHT || pos.y < 0) {
		vel.y *= -1;
		pos.y += vel.y * frameTime;
	}

	horse.setX(pos.x);
	horse.setY(pos.y);
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
    graphics->spriteBegin();                   // begin drawing sprites

    nebula.draw();                             // add the orion nebula to the scene
    planet.draw();                             // add the planet to the scene
	planet.setVisible(false);
	horse.draw(SETCOLOR_ARGB(255, 255, 0, 0)); // add the horse to the scene

    graphics->spriteEnd();                     // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Spacewar::releaseAll()
{
    planetTexture.onLostDevice();
    nebulaTexture.onLostDevice();
	horseTexture.onLostDevice();

    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Spacewar::resetAll()
{
    nebulaTexture.onResetDevice();
    planetTexture.onResetDevice();
	horseTexture.onResetDevice();

    Game::resetAll();
    return;
}
