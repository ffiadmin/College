#include "puck.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

//=============================================================================
// default constructor
//=============================================================================
Puck::Puck() : Entity()
{
    spriteData.width = puckNS::WIDTH;           
    spriteData.height = puckNS::HEIGHT;
    spriteData.x = puckNS::X;                   
    spriteData.y = puckNS::Y;
	setPosition(VECTOR2(puckNS::X, puckNS::Y));
    spriteData.rect.bottom = puckNS::HEIGHT/2;    // rectangle to select parts of an image
    spriteData.rect.right = puckNS::WIDTH;
    velocity.x = 0;                             // velocity X
    velocity.y = 0;                             // velocity Y
    startFrame = 0;              // first frame of ship animation
    endFrame     = 0;              // last frame of ship animation
    currentFrame = startFrame;
    collision = false;
    collisionType =entityNS::BOX;
    target = false;
	spriteData.scale = 1;
	mass = 1;
	edge.bottom = COLLISION_BOX_PUCK.bottom;
	edge.top = COLLISION_BOX_PUCK.top;
	edge.right = COLLISION_BOX_PUCK.right;
	edge.left = COLLISION_BOX_PUCK.left;

	srand(time(0));
}

bool Puck::initialize(Game *gamePtr, int width, int height, int ncols,
    TextureManager *textureM)
{
	directionY = -1;
	directionX = 1;

	reset();

    return(Entity::initialize(gamePtr, width, height, ncols, textureM));

}
void Puck::changeDirectionY()
{
	 directionY *= -1;
}
void Puck::changeDirectionX()
{
	 directionX *= -1;
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Puck::update(float frameTime)
{
    Entity::update(frameTime);

	//ADD code for puck to move left/right here


	//ADD "bounce" code here. Use the changeDirectionX() or changeDirectionY() functions
        

	//ADD spriteData.x, spriteData.y assignments here from Entity::positio
	if (getY() <= 0 || getY() + puckNS::HEIGHT >= GAME_HEIGHT) {
		velocity.y *= -1;
	}

	 this->spriteData.x += frameTime * this->velocity.x;
     this->spriteData.y += frameTime * this->velocity.y;
}

void Puck::reset() {
	float angle = rand() % 90;
	float dir = rand() % 2 == 0 ? 1 : -1;
	this->velocity.x = dir * puckNS::SPEED * sin(PI/180.0f * (45.0f + angle));
	this->velocity.y = dir * puckNS::SPEED * cos(PI/180.0f * (45.0f + angle));

	setX(puckNS::X);
	setY(puckNS::Y);
}

void Puck::bouncePaddle() {
	velocity.x *= -1;
}