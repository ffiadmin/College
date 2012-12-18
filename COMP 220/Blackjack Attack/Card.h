#ifndef __CARD_H
#define __CARD_H

#include <string>
using std::string;

enum Suit {clubs, diamonds, hearts, spades};
enum Value {deuce, trey, four, five, six, seven, eight, nine, ten, jack, king, queen, ace};

class Card {
public:
	Card(Value faceValue = deuce, Suit suit = clubs) : suit(suit), faceValue(faceValue) {}
	Suit getSuit() { return suit; }
	void setSuit(int s);
	void setValue(int v);
	Value getValue() { return faceValue; }
	string name() { return valueName(faceValue) + " of " + suitName(suit); }
	Card(Suit suit, Value facevalue);
	int calculateValue(Value v);
	void setCard(Suit s, Value v){suit=s;faceValue=v;};

	static string suitName(Suit s);
	static string valueName(Value v);

private:
	Suit suit;
	Value faceValue;
};

#endif