/**g
 * Assaults class
 *
 * This class is designed to manage assaults between two
 * territories
 *
 * @author    Zac Stahl
 * @namespace global
 * @package   assault
*/

#ifndef ASSAULT_H
#define ASSAULT_H

#include "Display.h"
#include "Player.h"
#include "Territory.h"
#include <iostream>
using std::cout;
using std::cin;
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
using std::endl;

class Assault {
private : 
    Territory *attTerr, *defTerr;
    bool isConquered();
    vector<int> attDice;
    vector<int> defDice;

public : 
    Assault(Territory*, Territory*);

    bool attack();
    int roll();
    void terrAcquisition(vector<Territory*> &terr);
};

#endif