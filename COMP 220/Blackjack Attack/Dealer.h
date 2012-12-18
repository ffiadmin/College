#include "Card.h"
#include "Player.h"
#include <iostream>
#include <vector>

class Dealer {
public:
	Dealer();
	void createDeck();
	int getDealersScore() {return cardsvalue;};
	int getCardNumber() {return cardnumber;};
	void shuffle();//changes the order that the cards will be read
	void showCard(int cardNum) {std::cout << deck[cardNum].name();};
	void dealersTurn();
	void playersTurn(Player& p, int round);
	int getOrder(int value) {return deckorder[value];};
	void setDealerScore(int score) {cardsvalue=score;};
	Card dealCard(int cardNum) {cardnumber++; return deck[deckorder[cardNum]];};
	void setCardNumber(int start) {cardnumber=start;};
	void takeCard(Card c) {hand.push_back(c);};
	void robPlayerBlind(Player& p);
	void setBust(bool b) {bust=b;};
	bool checkBust() {return bust;};
	int getHandSize() {return hand.size();};
	int getKnownScore() {return dealersKnownScore;};
	void setKnownScore(int score) {dealersKnownScore=score;};
	vector<Card> getHand() {return hand;};

private:
	vector<Card> hand;
	int dealersKnownScore;
	int cardsvalue;
	int cardnumber;
	int deckorder[52];//order of the deck that controls which card is which
	Card deck[52];
	bool bust;
};

