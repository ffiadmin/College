#include <ctime>
#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>

#include "Territory.h"
#include "Player.h"
#include "Deck.h"
#include "Display.h"
#include "Assault.h"
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::vector;

#ifndef GAME_H
#define GAME_H

const int INITIAL_TROOPS[5] = {40, 35, 30, 25, 20};
const int TURN_IN_CARDS[18] = {4, 6, 8, 10, 12, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75};

class Game
{
public:
	Game();

	void setup();
	void play();
	void firstTurn();

	void reinforcementsPhase(Player* p);
	void attackPhase(Player p);
	void fortifyPhase(Player p);
	void endTurn(Player* p);         //draw a card if a territory is conquered
private:
	vector <Player> players;
	Deck *deck;
	vector <Territory*> territories;
	vector<string> text;
	vector<char> align;

	vector<Territory*> playerOwns(Player *p);

	void initialTerrDistribution();
	void initialTroopDistribution();

	int roll();
	void pause();
	void setTitle(string title);
	int currentPlayer;
	bool terrConquered;
};

#endif