/* 
  Author:  Suite Team [Jake Gearhart, Jesse Ficter, Oliver Spryn]
  Course:  COMP 220, Computer Programming II 
  Date:    23 September 2012 
  Description:  This file implements the logic to visually format
                complicated character output to the console screen. 
*/

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "Config.h"
#include "Dealer.h"
#include "Display.h"
#include "Misc.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//Begin the game
Display::Display(void) {
	int round=0, win=0;
	int bet;
	char go;
	bool play=true, fail=false;
	std::cout << Config::GAME_NAME << "\n\n";
	std::cout << "Press Enter to start";
	std::cin.ignore();
	Misc::clear();
	std::cout << Config::WELCOME << "\n";
	std::cout << Config::INSTRUCTIONS << "\n\n";
	Player player;
	Dealer dealer;
	while(play && player.getChips() > 0)
	{
		//sets values to what they initially need to be
		player.setSurrender(false);
		player.setBust(false);
		dealer.setBust(false);
		round++;

		std::cout << "Press enter to start a game.";

		std::cin.ignore();
		Misc::clear();

		Display::userInfo(player.getChips(),player.getScore(),dealer.getKnownScore(),round);
		bet=0;
		std::cout << "\nYou have " << player.getChips() << " chips.";
		do
		{
			do
			{
				fail=false;
				std::cout << "\nPlace your bet: ";
				std::cin >> bet;
				while(std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(80,'\n');
					std::cout << "\That is invalid input\n";
					std::cout << "\nPlace your bet: ";
					std::cin >> bet;
				}
				if(bet<0)
				{
					fail=true;
					std::cout << "\nYou can't have a negative bet you silly";
				}
			}while(fail);

			if(bet>player.getChips())
			{
				std::cout << "\nYou dont have enough chips!\n";
			}
		}while(bet>player.getChips());

		dealer.setCardNumber(1);
		dealer.dealersTurn();
		dealer.playersTurn(player, round);
		Misc::clear();
		Display::userInfo(player.getChips(),player.getScore(),dealer.getKnownScore(),round);
		std::cout << "Dealer's cards:" << std::endl;
		Display::displayCard(dealer.getHand(),true);
		std::cout << "\nYour cards:" << std::endl;
		Display::displayCard(player.getHand(),false);
		if((dealer.checkBust() || dealer.getDealersScore()<=player.getScore()) && !player.checkBust())
		{
			if(dealer.getDealersScore()==player.getScore())
			{
				if(player.getHandSize()<dealer.getHandSize())
				{
					std::cout << "\nMy score was " << dealer.getDealersScore();
					std::cout << "\nYou won this round!\n"
						  << "Your chips will go up by " << bet << " chips.\n";
					player.setChips(player.getChips()+bet);
				}
				else
				{
				std::cout << "\nMy score was " << dealer.getDealersScore();
				std::cout << "\nYou lost this round!\n"
						  << "Your chips will go down by " << bet << " chips.\n";
				player.setChips(player.getChips()-bet);
				}
			}
			else
			{
				std::cout << "\nMy score was " << dealer.getDealersScore();
				std::cout << "\nYou won this round!\n"
						  << "Your chips will go up by " << bet << " chips.\n";
				player.setChips(player.getChips()+bet);
				win++;
			}
		}
		else
		{
			if(player.getSurrender())
			{
				std::cout << "\nMy score was " << dealer.getDealersScore();
				std::cout << "\nYou surrendered, you lose " << bet/2 << " chips\n";
				player.setChips(player.getChips()-(bet/2));
			}
			else
			{
				std::cout << "\nMy score was " << dealer.getDealersScore();
				std::cout << "\nYou lost this round!\n"
						  << "Your chips will go down by " << bet << " chips.\n";
				player.setChips(player.getChips()-bet);
			}
		}
		dealer.shuffle();
		dealer.setCardNumber(1);
		if(player.getScore()==26)
			dealer.robPlayerBlind(player);
		if(player.getChips()>0)
		{
			if(player.getChips()>=1000000)
			{
				std::cout << "\nYou have over 1 million chips!\nYou win the game!!!";
				play=false;
				std::cout << "\nYou finished " << round << " rounds and won " << win << " rounds\nThanks for playing...GET OUT!";
				std::cin.ignore();
			}
			else
			{
				std::cout << "\nAnother round?\n1=yes\nanything else=no\n";
				std::cin >> go;
				if(go!='1')
				{
					play=false;
					std::cout << "\nYou finished " << round << " rounds and won " << win << " rounds\nThanks for playing...GET OUT!";
					std::cin.ignore();
				}
			}
		}
		else
		{
			std::cout << "\nyou are out of chips you are a loser!";
			std::cout << "\nYou finished " << round << " rounds and won " << win << " rounds\nThanks for playing...GET OUT!\n\n";
			std::cin.ignore();
			play=false;
		}
	}
}

//Center the text within the avaliable width
void Display::center(string text, int avaliableWidth) {
	int length = text.length();
	double padding = (avaliableWidth - length) / 2.0;
	int paddingLeft = floor(padding);
	int paddingRight = ceil(padding);
	
	cout << Display::setw(paddingLeft) << text << Display::setw(paddingRight);
}

//Format the given text to the given color
void Display::coloredText(int text, int color) {
	Display::setTextColor(color);
	cout << text;
	Display::resetTextColor();
}

//Format the given text to the given color
void Display::coloredText(string text, int color) {
	Display::setTextColor(color);
	cout << text;
	Display::resetTextColor();
}

//Set the color of the text within the console to the default color
void Display::resetTextColor() {
	Display::setTextColor(Config::DEFAULT_CONSOLE_COLOR);
}

//Start coloring the output of text the specified color
void Display::setTextColor(int color) {
	HANDLE cHandle;
	cHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(cHandle, color);
}

//ASCII art from http://www.angelfire.com/art/lorriesascii/art1.html
//Display the visual ASCII representation of the card
void Display::displayCard(vector<Card> hand, bool isDealer) {
	int length = hand.size();

//Store the ASCII representations of each suit by row in an array
	string clubs[] = {"   _   ", " _( )_ ", "(__ __)", "   I   "};
	string diamonds[] = {"  / \\  ", " /   \\ ", " \\   / ", "  \\ /  "};
	string hearts[] = {" ** ** ", "*  *  *", " *   * ", "   *   "};
	string spades[] = {"   *   ", " *   * ", "*     *", "  *I*  "};

//Perform card spacial calculations
	int cardsWidthTotal = (length * Config::CARD_WIDTH) + ((length - 1) * 2);
	double padding = (Config::CONSOLE_WIDTH - cardsWidthTotal) / 2.0;
	int paddingLeft = floor(padding);
	int paddingRight = ceil(padding);
	
	for (int i = 0; i < Config::CARD_HEIGHT; i++) {
		cout << Display::setw(paddingLeft);
		
		for (int j = 0; j < length; j++) {
		//Print the top of the card
			if (i == 0) {
				cout << ".-------.";
			}

		//Print the left edge of the card, except for the first and last rows
			if (i != 0 && i != Config::CARD_HEIGHT - 1) {
				cout << "|";
			}

		//Print the suit
			if (i >= 1 && i <= 4) {
				string suit = hand[j].suitName(hand[j].getSuit());

				if (j == 0 && isDealer) {
					cout << Display::setw(Config::CARD_WIDTH - 2);
				} else {
					if (suit == "Hearts") {
						Display::coloredText(hearts[i - 1], red);
					} else if (suit == "Clubs") {
						Display::coloredText(clubs[i - 1], blue);
					} else if (suit == "Diamonds") {
						Display::coloredText(diamonds[i - 1], red);
					} else if (suit == "Spades") {
						Display::coloredText(spades[i - 1], blue);
					}
				}
			}

		//Echo a line between the suit and value
			if (i == 5) {
				cout << Display::setw(Config::CARD_WIDTH - 2); //-2 to account for the edges of the card
			}

		//Echo the value of the card
			if (i == 6) {
				if (j == 0 && isDealer) {
					cout << Display::setw(Config::CARD_WIDTH - 2);
				} else {
					Display::center(hand[j].valueName(hand[j].getValue()), Config::CARD_WIDTH - 2);
				}
			}

		//Display the right edge of the card, except for the first and last rows
			if (i != 0 && i != Config::CARD_HEIGHT - 1) {
				cout << "|";
			}

		//Print the bottom of the card
			if (i == Config::CARD_HEIGHT - 1) {
				cout << "'-------'";
			}

		//Don't put a space between the cards if this is the last letter
			if (j + 1 != length) {
				cout << "  ";
			}
		}

		cout << endl;
	}
}

//A working version of the built-in setw() function ;)
string Display::setw(int width) {
	string returnVal = "";

	for (int i = 1; i <= width; i++) {
		returnVal += " ";
	}

	return returnVal;
}

//Display the score of the user and dealer at the top of the screen
void Display::userInfo(int chipValue, int playerScore, int dealerScore, int round) {
	cout << "Your chip value: ";
	Display::coloredText(chipValue, green);
	cout << " Your score: ";
	Display::coloredText(playerScore, green);
	cout << " Dealer's known score: ";
	Display::coloredText(dealerScore, green);
	cout << " Round number: ";
	Display::coloredText(round, green);
	cout << endl
		 << "================================================================================";
}