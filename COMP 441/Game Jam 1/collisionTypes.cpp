// Programming 2D Games
// Copyright (c) 2011, 2012 by: 
// Charles Kelly
// Collision types demo
// Press '1', '2' or '3' to select collision type for ship.

#include "collisionTypes.h"

//=============================================================================
// Constructor
//=============================================================================
CollisionTypes::CollisionTypes() : puckDir(1), score1(0), score2(0), l(20), r(605)
{
	//nothing here, move on
}

//=============================================================================
// Destructor
//=============================================================================
CollisionTypes::~CollisionTypes()
{
    releaseAll();           // call onLostDevice() for every graphics item
	SAFE_DELETE(counterText1);
	SAFE_DELETE(counterText2);
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


	this->counterText1 = new TextDX();
	this->counterText2 = new TextDX();

	// initialize DirectX fonts
    if(this->counterText1->initialize(graphics, 20, true, false, "Calibri") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	if(this->counterText2->initialize(graphics, 20, true, false, "Calibri") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	/*// main game textures
    if (!gameTextures.initialize(graphics,TEXTURES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

    // nebula image
    if (!nebula.initialize(graphics,0,0,0,&nebulaTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));*/

	if (!dividerTM.initialize(graphics,DIVIDER_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing divider textures"));

	if (!divider.initialize(graphics,1,600,1,&dividerTM))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing divider"));

	if (!puckTM.initialize(graphics,PUCK_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing puck textures"));

   	if (!puck.initialize(this,0,0,0,&puckTM))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing puck"));

	if (!paddleTM.initialize(graphics,PADDLE_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle textures"));

	if (!l.initialize(this,0,0,0,&paddleTM))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle"));

	if (!r.initialize(this,0,0,0,&paddleTM))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle"));

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void CollisionTypes::update()
{
	graphics->setBackColor(SETCOLOR_ARGB(0,0,0,0));

	divider.setX(GAME_WIDTH / 2);
	divider.setY(00);

	//ADD Keyboard control code here
	if (input->isKeyDown(RESET_PUCK)) {
		puck.setActive(true);
		puck.setVisible();

		puck.setX(puckNS::X);
		puck.setY(puckNS::Y);
	}

	if (input->isKeyDown(PADDLE_L_UP)) {
		l.up();
	}

	if (input->isKeyDown(PADDLE_L_DOWN)) {
		l.down();
	}

	if (input->isKeyDown(PADDLE_R_UP)) {
		r.up();
	}

	if (input->isKeyDown(PADDLE_R_DOWN)) {
		r.down();
	}

	l.update(frameTime);
	r.update(frameTime);
	puck.update(frameTime);

	D3DXVECTOR2 v(0, 0);
	l.setVelocity(v);
	r.setVelocity(v);
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

	if (puck.collidesWith(l, collisionVector)) {
		puck.bouncePaddle();
		puck.setX(31);

		audio->playCue(HIT);
	}

	if (puck.collidesWith(r, collisionVector)) {
		puck.bouncePaddle();
		puck.setX(594);

		audio->playCue(HIT);
	}

	if (puck.getX() + puckNS::WIDTH >= GAME_WIDTH) {
		puck.reset();
		audio->playCue(OW);
		score1++;
	}

	if (puck.getX() <= 0) {
		puck.reset();
		audio->playCue(OW);
		score2++;
	}
}

//=============================================================================
// Render game items
//=============================================================================
void CollisionTypes::render()
{
	// Integer to string conversion here
	
    graphics->spriteBegin();                // begin drawing sprites
	std::stringstream ss;

	ss << score1;
	this->counterText1->setFontColor(graphicsNS::WHITE);
	this->counterText1->print(ss.str(),100,30);

	ss.str("");
	ss << score2;
	this->counterText2->setFontColor(graphicsNS::WHITE);
	this->counterText2->print(ss.str(),500,30);


	l.draw();
	r.draw();
    puck.draw();
	divider.draw();

	

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
