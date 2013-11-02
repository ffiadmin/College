#include <iostream>
#include <vector>
#include "Card.h"
using std::vector;

#ifndef CARD_GROUP
#define CARD_GROUP

class CardGroup
{
public:
	CardGroup() : largestName(0), sizeOfLargestValue(0) {}
	virtual int size() = 0;
	bool empty() {return size() == 0;}

	virtual void addCard(CardGroup& group) = 0;
	virtual vector<Card> removeCard() = 0;

protected:
	int largestName;
	int sizeOfLargestValue;
};

//returns -1 if user wishes not to choose
int getValidIntChoice(int acceptedValues[], int numValues);

#endif