/* 
  Author:  Suite Team [Jake Gearhart, Jesse Ficter, Oliver Spryn]
  Course:  COMP 220, Computer Programming II 
  Date:    23 September 2012 
  Description:  This file implements the logic to hold the player's
                cards, keeps track of their score, and share 
				information to the dealer. 
*/

#include "Player.h"
#include <iostream>

Player::Player(void) {
	chips=500;
	cardsValue=0;
}

void Player::createHand(Card first, Card second) {
	hand.push_back(first);
	std::cout << "\n\nyour first card is the " << first.name();
	hand.push_back(second);
	std::cout << "\nyour second card is the " << second.name() << "\n";
}

int Player::handValue() {
	int value = 0;
	for (int i = 0; i < hand.size(); i++) {
		int v = hand[i].calculateValue(hand[i].getValue()); //This will return the value of the card at i in hand
		value = value + v;
	}
	return value;
}

void Player::hit(Card c) {
	hand.push_back(c);
	std::cout << c.name();
}