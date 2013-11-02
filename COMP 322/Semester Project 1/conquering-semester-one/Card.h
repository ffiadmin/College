#include <string>
using std::string;
using std::istream;

#ifndef CARD_H
#define CARD_H

struct Card
{
	Card() : name("No_Name"), value(0){}
	Card(string n, int v) : name(n), value(v) {}

	bool anySet(); //determines if there is a set to play

	friend bool operator == (Card& left, Card& right);
	friend istream& operator >> (istream& in, Card& c);

	string name;
	int value;
};

#endif