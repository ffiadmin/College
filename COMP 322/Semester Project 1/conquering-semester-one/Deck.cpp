#include "Deck.h"
using std::swap;
using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::left;
using std::setw;

extern int nUniqueVal;

Deck::Deck(string filename)
{	
	ifstream fin;
	vector<int> uniqueVal;
	bool found = false;

	fin.open(filename);
	if(fin.fail()) {
		throw Failed_to_open_file_for_deck_input();
	}

	Card c;
	while(fin >> c) {
		deck.push_back(c);

		for(int i=0; i<uniqueVal.size(); i++) {
			if(uniqueVal[i] == c.value)
				found = true;
		}
		if(found == false)
			uniqueVal.push_back(c.value);
		else
			found = false;

		if(c.name.size() > largestName)
			largestName = c.name.size();
		
		string s = std::to_string((long long)c.value);
		//itoa(c.value, (char*)s.c_str(), 10);
		if(strlen(s.c_str()) > sizeOfLargestValue)
			sizeOfLargestValue = strlen(s.c_str());
	}
	nUniqueVal = uniqueVal.size();

	fin.close();
}

void Deck::addCard(CardGroup& group) //there is a problem here...hand.removeCard() always has an interface...
{
	vector<Card> v;
	v = group.removeCard();
	while(v.size() == 1 && group.size() >= 5) {
		v.clear();
		v = group.removeCard();
	}
	if(v.size() == 1)
		return;

	for(int i=0; i<v.size(); i++) {
		deck.push_front(v[i]);

		if(v[i].name.size() > largestName)
			largestName = v[i].name.size();

		string s = std::to_string((long long)v[i].value);
		//itoa(v[i].value, (char*)s.c_str(), 10);

		if(strlen(s.c_str()) > sizeOfLargestValue)
			sizeOfLargestValue = strlen(s.c_str());
	}
}

vector<Card> Deck::removeCard()
{
	if(empty()) {
		cout << "Error: cannot draw from an empty deck." << endl;
		throw Tried_to_draw_from_empty_deck();
	}
	vector<Card> temp;
	temp.push_back(deck.back());
	deck.pop_back();
	return temp;
}

void Deck::shuffle()
{
	int a, b, deckSize;

	deckSize = deck.size();
	for(int i=0; i<10000; i++)
	{
		a = rand() % deckSize;
		b = rand() % deckSize;
		swap(deck[a], deck[b]);
	}
}

void Deck::print()
{
	for(int i=0; i<deck.size(); i++) {
		cout << left << setw(largestName + 1) << deck[i].name;
		cout << left << setw(sizeOfLargestValue) << deck[i].value << endl;
	}	
}