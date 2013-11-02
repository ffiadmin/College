#include "TroopHandler.h"

/**
 * DEFAULT CONSTRUCTOR
 * 
 * This constructor assigns this territory 1 troop member upon creation.
 *
 * @access public
 * @return void
*/

TroopHandler::TroopHandler() : numTroops(0) { }

/**
 * Add a troop to this territory. If no parameters are supplied,
 * this function will add 1 troop member to the territory, otherwise
 * it will add the specified number up to MAX_TROOPS troops.
 * 
 * @access public
 * @param  int                     add The number of troops to add to this territory
 * @return void
 * @throws TroopModifierOutOfRange     Thrown when "add" is less than 0, or it causes the troop total to exceed MAX_TROOPS
*/

void TroopHandler::addTroop(int add) throw(TroopModifierOutOfRange) {
	if (this->numTroops + add > TroopHandler::MAX_TROOPS) {
		throw new TroopModifierOutOfRange("This maximum number of troops you may have on this territory is " + TroopHandler::MAX_TROOPS);
	} else if (add < 0) {
		throw new TroopModifierOutOfRange("You must add 0 or more troops to this territory");
	} else {
		this->numTroops += add;
	}
}

/**
 * Remove a troop from this territory. If no parameters are supplied,
 * this function will delete 1 troop member from the territory, otherwise
 * it will remove the specified number down to 1 troop.
 * 
 * @access public
 * @param  int                     del The number of troops to remove from this territory
 * @return void
 * @throws TroopModifierOutOfRange     Thrown when "del" is less than 0, or it causes the troop total to fall behind 1
*/

void TroopHandler::delTroop(int del) throw(TroopModifierOutOfRange) {
	if (this->numTroops - del < 0) {
		throw new TroopModifierOutOfRange("Somehow you have a negative number of troops. Please contact developers");
	} else if (del < 0) {
		throw new TroopModifierOutOfRange("You must remove 0 or more troops from this territory");
	} else {
		this->numTroops -= del;
	}
}

/**
 * Access the number of troops on this territory.
 * 
 * @access public
 * @return int    The number of troops on this territory
*/

int TroopHandler::getNumTroops() const {
	return this->numTroops;
}