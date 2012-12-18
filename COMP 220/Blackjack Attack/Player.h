#include "Card.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Player {
public:
	Player();
	int getScore() {return cardsValue;};
	void createHand(Card first, Card second);
	int handValue();
	int getHandSize() {return hand.size();};
	int getChips() {return chips;};
	Card viewHand(int n) {return hand[n];};
	void setScore(int score) {cardsValue = score;};
	void hit(Card c);
	void emptyHand() {hand.clear();};
	void setBust(bool b) {bust=b;};
	void setChips(int c) {chips=c;};
	bool checkBust() {return bust;};
	bool getSurrender() {return surrender;};
	void setSurrender(bool s) {surrender=s;};
	vector<Card> getHand() {return hand;};

private:
	vector<Card> hand;
	int chips, cardsValue;
	bool bust;
	bool surrender;

};