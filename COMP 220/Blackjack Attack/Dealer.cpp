/* 
  Author:  Suite Team [Jake Gearhart, Jesse Ficter, Oliver Spryn]
  Course:  COMP 220, Computer Programming II 
  Date:    23 September 2012 
  Description:  This file implements the logic to deal the cards
                and controls the turns of itself and the player. 
*/

#include "Dealer.h"
#include "Display.h"
#include "Card.h"
#include "Misc.h"
#include <ctime>
#include <iostream>
#include <string>

Dealer::Dealer() {
	createDeck();
	shuffle();
	setDealerScore(0);
	setKnownScore(0);
}

void Dealer::createDeck()
{
	deck[0].setCard(hearts,ace);
	deck[1].setCard(hearts,deuce);
	deck[2].setCard(hearts,trey);
	deck[3].setCard(hearts,four);
	deck[4].setCard(hearts,five);
	deck[5].setCard(hearts,six);
	deck[6].setCard(hearts,seven);
	deck[7].setCard(hearts,eight);
	deck[8].setCard(hearts,nine);
	deck[9].setCard(hearts,ten);
	deck[10].setCard(hearts,jack);
	deck[11].setCard(hearts,queen);
	deck[12].setCard(hearts,king);
	deck[13].setCard(diamonds,ace);
	deck[14].setCard(diamonds,deuce);
	deck[15].setCard(diamonds,trey);
	deck[16].setCard(diamonds,four);
	deck[17].setCard(diamonds,five);
	deck[18].setCard(diamonds,six);
	deck[19].setCard(diamonds,seven);
	deck[20].setCard(diamonds,eight);
	deck[21].setCard(diamonds,nine);
	deck[22].setCard(diamonds,ten);
	deck[23].setCard(diamonds,jack);
	deck[24].setCard(diamonds,queen);
	deck[25].setCard(diamonds,king);
	deck[26].setCard(spades,ace);
	deck[27].setCard(spades,deuce);
	deck[28].setCard(spades,trey);
	deck[29].setCard(spades,four);
	deck[30].setCard(spades,five);
	deck[31].setCard(spades,six);
	deck[32].setCard(spades,seven);
	deck[33].setCard(spades,eight);
	deck[34].setCard(spades,nine);
	deck[35].setCard(spades,ten);
	deck[36].setCard(spades,jack);
	deck[37].setCard(spades,queen);
	deck[38].setCard(spades,king);
	deck[39].setCard(clubs,ace);
	deck[40].setCard(clubs,deuce);
	deck[41].setCard(clubs,trey);
	deck[42].setCard(clubs,four);
	deck[43].setCard(clubs,five);
	deck[44].setCard(clubs,six);
	deck[45].setCard(clubs,seven);
	deck[46].setCard(clubs,eight);
	deck[47].setCard(clubs,nine);
	deck[48].setCard(clubs,ten);
	deck[49].setCard(clubs,jack);
	deck[50].setCard(clubs,queen);
	deck[51].setCard(clubs,king);

};

void Dealer::shuffle()
{
	bool used;
	srand(time(NULL));
	for(int i=0; i<52; i++)
	{
		used=false;
		do
		{
			deckorder[i] = (rand()%52);
			for(int j=1; j<1; j++)
			{
				if(deckorder[i]==deckorder[j])
				{
					used=true;
				}
			}
		}while(used);
	}
};

void Dealer::robPlayerBlind(Player& p)
{
	//This is an 'easter egg' in the game that steals your chips if your score is 26
	std::cout << "\nYour previous score was " << p.getScore()
			  << "\nI hate that number!!!"
			  << "\nI am taking all of your chips\nBLACKJACK ATTACK!!!\n";
	p.setChips(0);
};

void Dealer::dealersTurn()
{
	//This controls the dealers actions
	//he gets cards until he has a value over 17
	//The first card value is not known by the player
	setBust(false);
	hand.clear();
	Card dealerscard;
	int total=0, value=0, numAce = 0, cardnum=0, firstvalue=0;
	bool hasAce=false;
	do
	{
		dealerscard = dealCard(getCardNumber());
		cardnum++;
	
		if(cardnum==1)
		{
			firstvalue=dealerscard.calculateValue(dealerscard.getValue());
		}
		
		takeCard(dealerscard);
		value = dealerscard.calculateValue(dealerscard.getValue());
		if(value == 11)
		{
			hasAce=true;
			numAce++;
		}
		total+=value;

		if(total>21 && hasAce)
		{
			total-=10;
			numAce--;
			if(numAce==0)
			{
				hasAce=false;
			}
		}
		setDealerScore(total);
	}while(getDealersScore()<17);
	
	if (getDealersScore()>21)
	{
		setBust(true);
		if((getDealersScore()-firstvalue)>21)
		{
			std::cout << "\nI busted you win. Please stand with your current score\n";
		}
	}
	setKnownScore((getDealersScore()-firstvalue));
};

void Dealer::playersTurn(Player& p, int round)
{
	bool firstTurn;
	p.setBust(false);
	bool stop=false, hasAce=false;
	int numAce=0, choice = 0, acesUsed=0;
	p.emptyHand();
	string input;
	Card playersCard, first, second;
	first = dealCard(getCardNumber());
	second = dealCard(getCardNumber());
	p.createHand(first, second);
	p.setScore(p.handValue());
	if(first.calculateValue(first.getValue())==11)
	{
		hasAce=true;
		numAce++;
	}
	if(second.calculateValue(second.getValue())==11)
	{
		hasAce=true;
		numAce++;
	}
	if(p.getScore()==22)
	{
		numAce--;
		p.setScore(p.getScore()-10);
		acesUsed++;
	}
	firstTurn=true;

	do
	{	
		Misc::clear();
		Display::userInfo(p.getChips(),p.getScore(),getKnownScore(),round);
		std::cout << "Dealer's cards:" << std::endl;
		Display::displayCard(Dealer::hand,true);
		std::cout << "\nYour cards:" << std::endl;
		Display::displayCard(p.getHand(),false);
		std::cout << "\nwhat do you want to do? ";
		std::cin >> input;
		if(input=="hit")
			choice=1;
		if(input=="stand")
			choice=2;
		if(input=="surrender")
		{
			if(firstTurn)
				choice=3;
			else
			{
				std::cout << "\nIT IS TOO LATE TO SURRENDER MUWHAHA!\n";
				continue;
			}
		}

		switch(choice)
		{
			case 1:
				firstTurn=false;
				playersCard=dealCard(getCardNumber());
				if(playersCard.calculateValue(playersCard.getValue())==11)
				{
					hasAce=true;
					numAce++;
				}
				p.hit(playersCard);
				p.setScore((p.handValue() - acesUsed*10));
				std::cout << "\nHere is your current score: " << p.getScore();
				if(p.getScore() > 21 && hasAce)
				{
					std::cout << "\n you have an ace and your cards are over 21\n the ace value is now 1\n";
					p.setScore((p.getScore()-10));
					std::cout << "your score is " << p.getScore() << "\n";
					numAce--;
					acesUsed++;
					if(numAce==0)
					{
						hasAce=false;
					}
				}
				break;
			case 2:
				std::cout << "\nyou are staying at " << p.getScore() << "\n";
				stop=true;
				break;
			case 3:
				std::cout << "\nYou have chosen to surrender.\nYou will only lose half of your intitial bet\n";
				stop=true;
				p.setSurrender(true);
			default:
				stop=true;
		}
	}while(!stop && p.getScore()<=21);
	if(p.getScore() > 21)
	{
		std::cout << "\nyou bust haha\n";
		p.setBust(true);
	}
};