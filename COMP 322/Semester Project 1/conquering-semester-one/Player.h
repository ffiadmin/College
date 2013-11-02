#include <string>
#include <vector>
#include <map>
#include "Hand.h"
#include "Deck.h"
using std::string;
using std::vector;
using std::map;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player(string playerName, int playerColor, Deck* playerCards);
	string getName() {return name;}
	int getColor() {return color;}
	Hand* getHand() {return &hand;}
	Deck* getDeck() {return allCards;}

	friend bool operator == (Player& left, Player& right);
	friend bool operator != (Player& left, Player& right);
	bool isActive;
	int turnCard;

private:
	string name;
	int color;
	Deck *allCards;
	Hand hand;
};

#endif