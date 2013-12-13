/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the Flare class  
*/

#ifndef FLARE_H
#define FLARE_H
#define WIN32_LEAN_AND_MEAN

#include "Entity.h"

class Flare : public Entity {
public : 
        Flare(int width, int height);

        // Updates to this object will be managed by the Explode class
};

#endif