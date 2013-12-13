/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the Explode class  
*/

#ifndef EXPLODE_H
#define EXPLODE_H
#define WIN32_LEAN_AND_MEAN

#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <vector>

#include "Flare.h"
#include "game.h"
#include "gameError.h"
#include "graphics.h"
#include "Spark.h"
#include "TextureManager.h"

using std::cos;
using std::sin;
using std::vector;

namespace explodeNS {
	const char FLARE_ONE_IMAGE[]     = "pictures\\flare-one.png";
	const char FLARE_TWO_IMAGE[]     = "pictures\\flare-two.png";
	const char SPARK_IMAGE[]         = "pictures\\spark.jpg";

	const int FLARE_FADE_CONST       = 3;
    const int FLARE_HEIGHT           = 427;
    const int FLARE_WIDTH            = 640;
    const int SPARK_COLOR_TRANSITION = 100;
    const int SPARK_COUNT            = 500;
    const float SPARK_FRICTION       = 0.997f;
    const int SPARK_GROUP_CONSTRUCT  = 15;
    const int SPARK_LENGTH           = 50;
    const float SPARK_SPEED_CONST    = 3.5f;
    const int SPARK_WIDTH            = 1;
}

class Explode {
private : 
        Flare* flareOne;
        int flareOneAlpha;
        TextureManager flareOneTexture;
        Flare* flareTwo;
        int flareTwoAlpha;
        TextureManager flareTwoTexture;
        Game* gamePtr;
        vector<Spark> spark;
        int sparkCounter;
        TextureManager sparkTexture;
        float transBlue;
        float transGreen;
        float transRed;

public : 
        Explode(Graphics* g, Game* gamePtr);
        ~Explode();
        
        bool completed();
        void explodeAt(float x, float y);
};

#endif