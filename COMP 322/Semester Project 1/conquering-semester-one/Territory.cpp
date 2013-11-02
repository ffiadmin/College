#include "Territory.h"

/**
 * FRIEND FUNCTION
 * 
 * An overloaded == operator to determine if two Territory objects
 * are equal.
 *
 * @access public
 * @param  Territory& t1 The first Territory object to compare
 * @param  Territory& t2 The second Territory object to compare
 * @return bool          Whether the two territory objects are the same
*/

bool operator== (Territory& t1, Territory& t2) {
	return t1.name == t2.name;
}

/**
 * FRIEND FUNCTION
 * 
 * An overloaded != operator to determine if two Territory objects
 * are not equal.
 *
 * @access public
 * @param  Territory& t1 The first Territory object to compare
 * @param  Territory& t2 The second Territory object to compare
 * @return bool          Whether the two territory objects are not the same
*/

bool operator!= (Territory& t1, Territory& t2) {
	return t1.name != t2.name;
}

void Territory::addTangent(Territory* tangent) {
	this->tangent.push_back(tangent);
}

/**
 * DEFAULT CONSTRUCTOR
 * 
 * This constructor assigns the member variables their values given to
 * this constructor, and calls this class's super constructor.
 *
 * @access public
 * @param  string             name      The string name of this territory
 * @return void
*/

Territory::Territory(string name) : TroopHandler(), name(name) { }

/**
 * Access the name of the territory.
 *
 * @access public
 * @return string The name of the territory
*/

string Territory::getName() {
	return this->name;
}

/**
 * Access the owner of this territory.
 *
 * @access public
 * @return string The owner of this territory
*/

Player* Territory::getOwner() {
	return owner;
}

vector<Territory*> Territory::getTanget() {
	return this->tangent;
}

/**
 * Determine whether this territory is tangent to another territory.
 *
 * @access public
 * @param  Territory& territory A Territory object to check against the current Territory object
 * @return bool                 Whether this territory is tangent to the one passed in as an argument
*/

bool Territory::isTangentTo(Territory* territory) {
	for (vector<Territory*>::iterator it = this->tangent.begin(); it != this->tangent.end(); ++it) {
		if (*it == territory) {
			return true;
		}
	}

	return false;
}

/**
 * Set a new owner for this territory.
 *
 * @access public
 * @param  Player& owner The new owner for this territory
 * @return void
*/

void Territory::setOwner(Player* owner) {
	this->owner = owner;
}