#include "Card.h"

bool operator == (Card& left, Card& right)
{
	return ((left.name == right.name) && (left.value == right.value));
}

istream& operator >> (istream& in, Card& c)
{
	string n, v;

	std::getline(in, n);
	std::getline(in, v);	

	c.name = n;
	c.value = atoi(v.c_str());

	return in;
}