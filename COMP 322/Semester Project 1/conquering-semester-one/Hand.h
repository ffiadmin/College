#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "CardGroup.h"
#include "Display.h"
using std::vector;
using std::string;
using std::stringstream;

#ifndef HAND_H
#define HAND_H


class Hand : public CardGroup
{
public:
	virtual int size() {return hand.size();}
	virtual void addCard(CardGroup& group);
	virtual vector<Card> removeCard(); //returns a vector<Card> of size 1 with the Card() if the user doesn't want to remove cards
	vector<Card> flush();
	void receiveHand(vector<Card> h);
	bool hasTerrCard(string terrName);
	void print();
	string getLastCardName() { return hand.back().name; }

private:
	vector<Card> hand;
};

class Tried_to_remove_card_from_empty_hand {};
class Tried_to_remove_nonexistent_card {};

#endif