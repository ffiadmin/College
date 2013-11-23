

#include "collisionTypes.h"



//=============================================================================
// Constructor
//=============================================================================
CollisionTypes::CollisionTypes()
{
	//nothing here, move on
}

//=============================================================================
// Destructor
//=============================================================================
CollisionTypes::~CollisionTypes()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void CollisionTypes::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

	mainMenu = new Menu();
	mainMenu->initialize(graphics, input);
	outString = "Selected Item: ";
	output = new TextDX();
	if(output->initialize(graphics, 15, true, false, "Arial") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing output font"));
    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void CollisionTypes::update()
{
	mainMenu->update();
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void CollisionTypes::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void CollisionTypes::collisions()
{
}

//=============================================================================
// Render game items
//=============================================================================
void CollisionTypes::render()
{
	std::stringstream ss;
	ss << outString;
	ss << mainMenu->getSelectedItem();

    graphics->spriteBegin();                // begin drawing sprites
	mainMenu->displayMenu();
	output->print(ss.str(), 0,0);
    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void CollisionTypes::releaseAll()
{
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void CollisionTypes::resetAll()
{
    Game::resetAll();
    return;
}
