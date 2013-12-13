/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file implements the Flare class  
*/

#include "Flare.h"

Flare::Flare(int width, int height) {
        this->collisionType     = entityNS::NONE;
        this->spriteData.height = height;
        this->spriteData.scale  = 1;
        this->spriteData.width  = width;
}