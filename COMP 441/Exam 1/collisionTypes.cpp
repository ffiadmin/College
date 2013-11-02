// Programming 2D Games
// Copyright (c) 2011, 2012 by: 
// Charles Kelly
// Collision types demo
// Press '1', '2' or '3' to select collision type for ship.

#include "collisionTypes.h"

//=============================================================================
// Constructor
//=============================================================================
CollisionTypes::CollisionTypes() : puckDir(1)
{
	//nothing here, move on
}

//=============================================================================
// Destructor
//=============================================================================
CollisionTypes::~CollisionTypes()
{
    releaseAll();           // call onLostDevice() for every graphics item
	SAFE_DELETE(counterText);
	SAFE_DELETE(audio);
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void CollisionTypes::initialize(HWND hwnd)
{
    Game::initialize(hwnd); 

	//ADD Puck and Paddle initialization code here
    
	//ADD Font initialization code here


	this->counterText = new TextDX();

	// initialize DirectX fonts
    if(this->counterText->initialize(graphics, 20, true, false, "Calibri") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	/*// main game textures
    if (!gameTextures.initialize(graphics,TEXTURES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

    // nebula image
    if (!nebula.initialize(graphics,0,0,0,&nebulaTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));*/

	if (!puckTM.initialize(graphics,PUCK_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing puck textures"));

   	if (!puck.initialize(this,0,0,0,&puckTM))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing puck"));

	if (!paddleTM.initialize(graphics,PADDLE_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle textures"));

	if (!paddle.initialize(this,0,0,0,&paddleTM))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle"));

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void CollisionTypes::update()
{
	//ADD Keyboard control code here
	if (input->isKeyDown(PADDLE_LEFT) && !input->isKeyDown(PADDLE_UP)) {
		paddle.setX(paddle.getX()-1);

		if (paddle.getX() <= 0) {
			paddle.setX(GAME_WIDTH - 81);
		}
	}

	if (input->isKeyDown(PADDLE_RIGHT) && !input->isKeyDown(PADDLE_UP)) {
		paddle.setX(paddle.getX()+1);

		if (GAME_WIDTH <= paddle.getX() * paddle.getScale() + 81) {
			paddle.setX(1);
		}
	}

	if (input->isKeyDown(PADDLE_UP)) {
		paddle.up();
		paddle.setY(paddle.getY()-1);

		if (paddle.getY() <= 0) {
			paddle.setX(paddleNS::X);
			paddle.setY(paddleNS::Y);
			paddle.setVelocity(D3DXVECTOR2(0.0, 0.0));
		}
	}

	if (puck.getX() + 60 >= GAME_WIDTH) {
		puckDir = -1;
	} 

	if (puck.getX() == 0) {
		puckDir = 1;
	}

	puck.setX(puck.getX() + puckNS::SPEED * frameTime * puckDir);

	paddle.update(frameTime);
	puck.update(frameTime);


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
    collisionVector.x = 0;      // clear collision vector
    collisionVector.y = 0;
	//ADD Collision detection code here
	

	/*VECTOR2 collisionVector;
    // if collision between ship and planet
    if(ship1.collidesWith(planet, collisionVector))
    {
        // bounce off planet
        ship1.bounce(collisionVector, planet);
        ship1.damage(PLANET);
		this->totalCol++;
    }
	
	
	//audio->playCue(EXPLOSION_CUE);
	*/
}

//=============================================================================
// Render game items
//=============================================================================
void CollisionTypes::render()
{
	// Integer to string conversion here
	std::stringstream ss;

	ss << "Hits: " << 0;
	
    graphics->spriteBegin();                // begin drawing sprites
	paddle.draw();
    puck.draw();

	this->counterText->setFontColor(graphicsNS::RED);
	this->counterText->print(ss.str(),GAME_WIDTH / 2 - 25,GAME_HEIGHT / 2);

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void CollisionTypes::releaseAll()
{
	paddleTM.onLostDevice();
	puckTM.onLostDevice();
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void CollisionTypes::resetAll()
{
	paddleTM.onResetDevice();
	puckTM.onResetDevice();
    Game::resetAll();
    return;
}
