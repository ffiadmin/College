/* 
  Author:  Suite Team [Jake Gearhart, Jesse Ficter, Oliver Spryn]
  Course:  COMP 220, Computer Programming II 
  Date:    23 September 2012 
  Description:  This file implements the logic to create and retrieve
                data for the Card object. 
*/

#include "Card.h"
#include <stdexcept>

string Card::suitName(Suit s) {
	switch(s) {
		case clubs: return "Clubs";
		case diamonds: return "Diamonds";
		case hearts: return "Hearts";
		case spades: return "Spades";
		default: throw std::out_of_range("Suit value out of range");
	}
}

string Card::valueName(Value v) {
	switch(v) {
		case ace: return "Ace";
		case deuce: return "Deuce";
		case trey: return "Trey";
		case four: return "Four";
		case five: return "Five";
		case six: return "Six";
		case seven: return "Seven";
		case eight: return "Eight";
		case nine: return "Nine";
		case ten: return "Ten";
		case jack: return "Jack";
		case queen: return "Queen";
		case king: return "King";
		default: throw std::out_of_range("Face value out of range");
	}
}

Card::Card(Suit suit, Value facevalue)
{
	Card::suit=suit;
	Card::faceValue=facevalue;
};

int Card::calculateValue(Value v)
{
	switch(v) {
		case ace: return 11;//start with the value of 11 automatically and if they go over it will reduce to 1
		case deuce: return 2;
		case trey: return 3;
		case four: return 4;
		case five: return 5;
		case six: return 6;
		case seven: return 7;
		case eight: return 8;
		case nine: return 9;
		case ten: return 10;
		case jack: return 10;
		case queen: return 10;
		case king: return 10;
		default: throw std::out_of_range("Face value out of range");
	}
};