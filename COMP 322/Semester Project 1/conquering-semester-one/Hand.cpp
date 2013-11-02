#include "Hand.h"
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::string;

void Hand::addCard(CardGroup& group) {
	vector<Card> v;
	v = group.removeCard();
	hand.push_back(v[0]);
	if(v[0].name.size() > largestName)
		largestName = v[0].name.size();

	string s;
	stringstream ss;
	ss << v[0].value;
	s = ss.str();
	ss.clear();
	
	if(strlen(s.c_str()) > sizeOfLargestValue)
		sizeOfLargestValue = strlen(s.c_str());
}

vector<Card> Hand::removeCard() {
	vector<Card> c;
	bool validSet = true;
	if(empty()) {
		cout << "Error: Cannot remove card from an empty hand" << endl;
		throw(Tried_to_remove_card_from_empty_hand());
	}

	int choice = -1;

	int *options = new int[hand.size()];
	for(int i=0; i<hand.size(); i++)
		options[i] = i+1;
	//may not need this...
	//system("cls");
	//******************
	do {
	for(int j=0; j<3; j++) {
		vector<string> title;
		vector<char> align;

		title.push_back("Turning in Cards");
		align.push_back('C');

		Display::clear();
		Display::setTextColor(gBlack);
		cout << Display::distribute(title, align);
		Display::resetTextColor();
		cout << endl;

		for(int i=0; i<hand.size(); i++) {
			cout << left << "(" << options[i] << ")";
			cout << left << setw(largestName + 2) << hand[i].name;
			cout << left << setw(sizeOfLargestValue) << hand[i].value << endl << endl;
		}
		if(validSet == false)
			cout << "invalid set." << endl;
		if(c.size() != 0)
			cout << "Selected: ";
		for(int i=0; i<c.size(); i++)
			cout << c[i].name << "\t";
		if(c.size() != 0)
			cout << endl;
		while(choice == -1) {
			cout << "Please enter the number of the card you wish to discard" << endl;
			cout << "Choice: ";
			choice = getValidIntChoice(options, hand.size()+1);
		}

		c.push_back(hand.at(choice-1));
		choice = -1;
	}
	validSet = ((c[0].value == c[1].value && c[1].value == c[2].value) ||
				(c[0].value != c[1].value && c[1].value != c[2].value && c[2].value != c[0].value));
	if(!validSet)
		c.clear();

	} while(validSet == false);

	delete [] options;

	for(int i=hand.size()-1; i >= 0; i--) {
		for(int j=0; j<3; j++) {
			if(hand[i] == c[j])
				hand.erase(hand.begin()+i);
		}
	}
	return c;
}

vector<Card> Hand::flush()
{
	vector<Card> temp = hand;
	hand.clear();
	return temp;
}
void Hand::receiveHand(vector<Card> h)
{
	hand.insert(hand.end(), h.begin(), h.end());
}

bool Hand::hasTerrCard(string terrName){
	for(auto i = hand.begin(); i != hand.end(); i++) {
		if(i->name == terrName)
			return true;
	}
	return false;
}

void Hand::print() {
	for(int i=0; i<hand.size(); i++) {
		cout << left << setw(largestName + 1) << hand[i].name;
		cout << left << setw(sizeOfLargestValue) << hand[i].value << endl;
	}
}