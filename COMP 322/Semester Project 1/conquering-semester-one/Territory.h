/**
 * Troop Handler class
 *
 * This class is designed to manage all of the territory and
 * troop related responsibilities for this game.
 *
 * @author    Oliver Spryn
 * @namespace global
 * @package   territory
*/

#ifndef TERRITORY_H
#define TERRITORY_H

#include "Display.h"
#include "Player.h"
#include <string>
#include "TroopHandler.h"
#include <vector>

using std::string;
using std::vector;

class Territory : public TroopHandler {
private : 
	int color;
	string continent;
	string name;
	Player* owner;
	vector<Territory*> tangent;

public : 
	friend bool operator== (Territory& t1, Territory& t2);
	friend bool operator!= (Territory& t1, Territory& t2);

	Territory(string);

	void addTangent(Territory*);
	string getName();
	Player* getOwner();
	vector<Territory*> getTanget();
	bool isTangentTo(Territory*);
	void setOwner(Player*);
};

#endif