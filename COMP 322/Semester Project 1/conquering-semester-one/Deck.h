#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
#include <iomanip>
#include "CardGroup.h"
#include "Card.h"
using std::istream;
using std::string;
using std::deque;

#ifndef DECK_H
#define DECK_H

class Deck : public CardGroup {
public:
	Deck(string filename);
	virtual int size() {return deck.size();}
	virtual void addCard(CardGroup& group);
	virtual vector<Card> removeCard();
	void shuffle();
	void print();

private:
	deque<Card> deck;
};

class Failed_to_open_file_for_deck_input {};
class Tried_to_draw_from_empty_deck {};

#endif