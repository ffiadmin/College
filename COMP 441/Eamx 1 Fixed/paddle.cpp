
#include "paddle.h"

//=============================================================================
// default constructor
//=============================================================================
Paddle::Paddle() : Entity()
{
    spriteData.width = paddleNS::WIDTH;           
    spriteData.height = paddleNS::HEIGHT;
    spriteData.x = paddleNS::X;                   
    spriteData.y = paddleNS::Y;
    spriteData.rect.bottom = paddleNS::HEIGHT/2;    
    spriteData.rect.right = paddleNS::WIDTH;
    velocity.x = 0;                             
    velocity.y = 0;                             
    startFrame = 0;              
    endFrame     = 0;              
    currentFrame = startFrame;
    collision = false;
    collisionType =entityNS::BOX;
    target = false;
	mass = 1;
	edge.bottom = COLLISION_BOX_PADDLE.bottom;
	edge.top = COLLISION_BOX_PADDLE.top;
	edge.right = COLLISION_BOX_PADDLE.right;
	edge.left = COLLISION_BOX_PADDLE.left;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Paddle::initialize(Game *gamePtr, int width, int height, int ncols,
    TextureManager *textureM)
{
    return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Paddle::update(float frameTime)
{
    Entity::update(frameTime);
	D3DXVECTOR2 v = getVelocity();

	spriteData.x = getX() + v.x * frameTime;
	spriteData.y = getY() + v.y * frameTime;

	if (getX() <= 0) {
		setX(GAME_WIDTH - 82);
	}

	if (GAME_WIDTH <= getX() * getScale() + 81) {
		setX(1);
	}

    //ADD POSITION UPDATING HERE
	//D3DXVECTOR2 v = getVelocity();
	//setY(getX() + v.x * frameTime);
	//setY(getY() + v.y * frameTime);
	
    // ADD WRAPPING CODE HERE.
   

	// ADD "Top of screen" CODE HERE
	
	
	//ADD spriteData.x, spriteData.y assignments here from Entity::position
	
	

}