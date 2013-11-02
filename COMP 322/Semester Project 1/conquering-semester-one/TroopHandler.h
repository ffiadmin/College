/**
 * Troop Handler class
 *
 * This class is designed to manage all of the troop-related
 * actions which is necessary for a territory. Its features 
 * include:
 *  - Add a troop to a territory.
 *  - Get the number of troops on a territory.
 *  - Remove a troop from a territory.
 *
 * @abstract
 * @author    Oliver Spryn
 * @namespace global
 * @package   territory
*/

#ifndef TROOPHANDLER_H
#define TROOPHANDLER_H

#include "TroopModifierOutOfRange.h"

class TroopHandler {
private : 
	static const int MAX_TROOPS = 100;

protected : 
	int numTroops;

public : 
	TroopHandler();
	void addTroop(int = 1) throw(TroopModifierOutOfRange);
	void delTroop(int = 1) throw(TroopModifierOutOfRange);
	int getNumTroops() const;
};

#endif