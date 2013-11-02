#include "Game.h"
#include "windows.h"
using std::map;

Game::Game() : deck(new Deck("card-list.txt")), terrConquered(false) {
	srand(time(0));
	text.push_back("Replace me :D");
	align.push_back('C');

//Initialize teh Territory pointerz :)
	ifstream fin, fin2;
	char terr[256];
	char tangent[256];
	fin.open("territory-list.txt");
	fin2.open("territory-list.txt");
	
//Add each of the territories to a container
	while(!fin.eof()) {
		fin.getline(terr, 256);

	//Lines that begin with a tab indicate tangent territories
		if (terr[0] != '\t')
			territories.push_back(new Territory(terr));
	}

//Start anew <--- poetic ;)
//	fin.seekg(0);

//Add each of the tangent territories
	string convert;
	fin2.getline(tangent, 256); // Get the first territory out of the way ;)

	for(int i = 0; i < territories.size(); ++i) {
	//Lines that begin with a tab indicate tangent territories
		while(true) {
			fin2.getline(tangent, 256);

			if (tangent[0] == '\t') {
				convert = tangent;
				convert = convert.substr(1);

				for (int j = 0; j < territories.size(); ++j) {
					if (territories[j]->getName() == convert) {
						territories[i]->addTangent(territories[j]);
					}
				}
			} else {
				break;
			}
		}
	}

	fin.close();
	fin2.close();

	deck->shuffle();
	int a, b, c = territories.size();

	for(int i=0; i<10000; i++)
	{
		a = rand() % c;
		b = rand() % c;
		std::swap(territories[a], territories[b]);
	}
}

void Game::setup()
{
//Assign the colors
	vector<int> colors;
	colors.push_back(white);
	colors.push_back(red);
	colors.push_back(pink);
	colors.push_back(yellow);
	colors.push_back(blue);
	colors.push_back(green);

	vector<string> colorNames;
	colorNames.push_back("white");
	colorNames.push_back("red");
	colorNames.push_back("pink");
	colorNames.push_back("yellow");
	colorNames.push_back("blue");
	colorNames.push_back("green");

//Get number of players
    int numPlayers = 2;

	do {
		setTitle("Beginning the Game");

		if (!cin || numPlayers < 2 || numPlayers > 6) {
			Display::coloredText("Try again, dude...", red);
			cout << endl;
		}

		cin.clear();
		cin.sync();

		cout << "Enter the number of players (2-6): ";
		cin >> numPlayers;
	} while (!cin || numPlayers < 2 || numPlayers > 6);
	

//Build the set of information for creating the Player class
	setTitle("Getting to Know You");
	cout << numPlayers << " players" << endl << endl;

	for(int i = 0; i < numPlayers; ++i) {
	//Get name of player
		char name[256];
		
		cout << "Player " << i + 1 << ", enter your name: ";

		cin.sync();
		cin.getline(name, 256);
        Player player(name,colors[i], deck);
		
	//Add the Player to the container
		players.push_back(player);
    }

//Show the players their colors
	setTitle("Assigning Player Colors");

	for(int i = 0; i < numPlayers; ++i) {
		Display::setTextColor(colors[i]);
		cout << players[i].getName() << ":" << endl
			 << "\tYou have been assigned the " << colorNames[i] << " color" << endl << endl;
	}

	Display::resetTextColor();

	cout << endl << "Please obtain the appropriate colored pieces for the game.";
	pause();
}
void Game::play()
{
	firstTurn();
	int i = 0;
	while(true){
		for(i=currentPlayer; i<players.size(); i++) {
			if(players[i].isActive)
			{
				reinforcementsPhase(&players[i]);    //reinforcements phase
				attackPhase(players[i]);    //attack phase
				fortifyPhase(players[i]);	//fortify phase
				if (terrConquered) {
					endTurn(&players[i]);    //draw a card if a territory is conquered
					terrConquered = false;
				}
			}
		}
		currentPlayer = 0;
	}

	for(i=currentPlayer; i<players.size(); i++) {
		cout << endl << endl << players[i].getName() << ", is the awesome winner!!!" << endl;
	}
}

void Game::firstTurn()
{
	setTitle("Determining Who Starts the Game");

	int numPlayers = players.size();
    int numTrues = 0;
    vector<bool> maybeFirst;
    for(int i = 0; i<numPlayers; i++)
	    maybeFirst.push_back(true);

    vector<int> rolls;
	    for(int i = 0; i<numPlayers; i++) {
		    if(maybeFirst[i])
			    rolls.push_back(roll());
        }

    do {
	    for(int i = 0; i<numPlayers; i++) {
		    if(maybeFirst[i])
			    rolls[i] = roll();
        }
	
	    for(int i=0; i<numPlayers-1; i++) {
		    if(maybeFirst[i]) {
			    for(int j=i+1; j<numPlayers; j++) {
				    if(maybeFirst[j]) {
					    if(rolls[i] > rolls[j])
                            maybeFirst[j] = false;
                        else if(rolls[i] < rolls[j]) {
                           maybeFirst[i] = false;
                           break;
                        }
				    }				
			    }
		    }
	    }
      
        numTrues = 0;
        for(int i =0; i<numPlayers; i++)
            if(maybeFirst[i])
                numTrues++;
    } while(numTrues > 1);

	int i = 0;

	for(i; i<numPlayers; i++) {
		if(maybeFirst[i]) {
			Display::setTextColor(players[i].getColor());
			cout << endl << players[i].getName();
			Display::resetTextColor();
			cout << " rolled the highest dice, and will go first!" << endl;
			currentPlayer = i;
			break;
		}
    }

	pause();
	Display::clear();

	//distributing soldiers.
	initialTerrDistribution();
	initialTroopDistribution();

	Display::clear();
}

void Game::reinforcementsPhase(Player* p) {
	vector<Territory*> terrRet = playerOwns(p);
	int troopCount = 0, terrCount = terrRet.size(), terrNum;
	troopCount = std::floor(terrCount/3.0);
	if(troopCount < 3)
		troopCount = 3;

//Card stuff?
	if (p->getHand()->size() >= 3) {
		setTitle("Turning in Cards");

		if (p->getHand()->size() < 5) {
			cout << "You have " << p->getHand()->size() << " cards. Would you like to turn some in now? (Y/N) ";

			char c;
			cin >> c;
		
			if(c=='y' || c =='Y') {
				setTitle("Turning in Cards");

				deck->addCard(*p->getHand());
				p->turnCard++;
			}
		} else {
			setTitle("Turning in Cards");
			cout << "You have " << p->getHand()->size() << " cards. You must trade in at least one set.";

			deck->addCard(*p->getHand());
			p->turnCard++;
		}

		troopCount += TURN_IN_CARDS[p->turnCard - 1];
	}
	
	while(troopCount > 0) {
		setTitle("Reinforcement Phase");
		while(p->getHand()->size() > 5)
			deck->addCard(*p->getHand());
		if(p->getHand()->size() >= 3)
			deck->addCard(*p->getHand());


		for(int i = 0; i < terrRet.size(); i++) {
			cout << i+1 << ". " << terrRet[i]->getName() << " (Troops: " << terrRet[i]->getNumTroops() << ")" << endl;
		}

		Display::setTextColor(p->getColor());
		cout << endl;
		cout << p->getName() << ",  choose a territory to reinforce (remaining: " << troopCount << "): ";
		Display::resetTextColor();
		cin >> terrNum;
		terrRet[terrNum-1]->addTroop();
		troopCount--;
	}
}
void Game::attackPhase(Player p) {
    while(true) {
	    setTitle("Attack Phase");
	    while(true) {
		    vector<Territory *> attTerr;
		    // populate list of territories that the player can attack from (with # of troops in parenthesis)
		    for(int i = 0; i < territories.size(); i++) {
			    if(territories[i]->getOwner()->getColor() == p.getColor()) {
				    attTerr.push_back(territories[i]);
				    cout << attTerr.size() << ". " << territories[i]->getName() << " (Troops: " << territories[i]->getNumTroops() << ")" << endl;
			    }
		    }

            int a=-1;
		    do {
		        Display::setTextColor(p.getColor());
			    cout << endl;
			    cout << p.getName() << ", choose a territory to attack from (or 0 to not): ";
			    Display::resetTextColor();
			    cin >> a;
				if(a == 0)
					return;
                cout << '\n';

                if (!cin || a<1 || a > territories.size()) {
			        Display::coloredText("Try again", red);
			        cout << endl;
		        }
                else if (attTerr[a-1]->getNumTroops() == 1) {
                    Display::coloredText("Try again, Not enough troops with which to attack", red);
			        cout << endl;
		        }

		        cin.clear();
		        cin.sync();
	        } while (!cin || a<1 || a > territories.size() || attTerr[a-1]->getNumTroops() == 1);

		    //populate a list of territories that the player can attack (with the # of troops in parenthesis)
		    vector<Territory *> defTerr;
		    for(int i = 0; i < territories.size(); i++) {
			    if(territories[i]->getOwner()->getColor() != p.getColor() && attTerr[a-1]->isTangentTo(territories[i])) {
				    defTerr.push_back(territories[i]);
				    cout << defTerr.size() << ". " << territories[i]->getName() << " (Troops: " << territories[i]->getNumTroops() << ")" << endl;
			    }
		    }
            
            if(defTerr.size() > 0) {
		        int d=-1;
		        do {
		            Display::setTextColor(p.getColor());
			        cout << endl;
			        cout << p.getName() << ", choose a Territory to attack: ";
			        Display::resetTextColor();
			        cin >> d;
                    cout << '\n';

                    if (!cin || d<1 || d > territories.size()) {
			            Display::coloredText("Try again", red);
			            cout << endl;
		            }
                
		            cin.clear();
		            cin.sync();
	            } while (!cin || d<1 || d > territories.size());

                Assault battle(attTerr[a-1], defTerr[d-1]);  // instantiates object of type Assault that handles the battle
			    
                if(battle.attack()) {  //begins the assault
				    terrConquered = true;    //set player value that holds if a territory was conquered to true
				    battle.terrAcquisition(territories);
			    } else {
					cout << "Well... that didn't go so well. :(" << endl << endl
						 << "  .-'---`-." << endl
						 << ",'          `." << endl
						 << "|             \\" << endl
						 << "|              \\" << endl
						 << "\           _  \\" << endl
						 << ",\  _    ,'-,/-)\\" << endl
						 << "( * \ \,' ,' ,'-)" << endl
						 << " `._,)     -',-')" << endl
						 << "   \/         ''/" << endl
						 << "    )        / /" << endl
						 << "   /       ,'-'" << endl;
				}
            }
            else {
                Display::coloredText("Try again, There are no territories you can attack from there.\n\n", red);
            }
        char c;
        cout << endl << "Would you like to attack another territory? (Y/N) : " ; 
        cin >> c;   //get if user would like to attack again if he can
		Display::clear();
        if(c=='n' || c =='N')
            return;
        }
    }
}
void Game::fortifyPhase(Player p) {
	vector<Territory*> terrRet = playerOwns(&p);
	int terrNumF, terrNumT, troopCount;

	do {
		setTitle("Reinforcement Phase");

		for(int i = 0; i < terrRet.size(); i++) {
			cout << i+1 << ". " << terrRet[i]->getName() << " (Troops: " << terrRet[i]->getNumTroops() << ")" << endl;
		}
		cout << endl;
		Display::setTextColor(p.getColor());
		cout << "Choose a territory to relocate from (or 0 to not): ";
		Display::resetTextColor();
		cin >> terrNumF;
		if(terrNumF == 0)
			return;
	//Check to see if the input is valid
		if (terrNumF < 0 || terrNumF > terrRet.size() - 1) {
			continue;
		}
		Display::setTextColor(p.getColor());
		cout << "Choose the number of troops to move: ";
		Display::resetTextColor();
		cin >> troopCount;

		if (troopCount <= 0 || terrRet[terrNumF - 1]->getNumTroops() - 1 < troopCount) {
			continue;
		}

		Display::clear();

	//Display the tangent territories
		vector<Territory*> tangent = terrRet[terrNumF - 1]->getTanget();

		for(int i = 0; i < tangent.size(); ++i) {
			cout << i+1 << ". " << tangent[i]->getName() << " (Troops: " << tangent[i]->getNumTroops() << ")" << endl;
		}
		Display::setTextColor(p.getColor());
		cout << "Choose a territory to relocate to: ";
		Display::resetTextColor();
		cin >> terrNumT;

	//Check to see if the input is valid
		if (terrNumF <= 0 || terrNumF > tangent.size() - 1) {
			continue;
		}

		terrRet[terrNumF - 1]->delTroop(troopCount);
		tangent[terrNumT - 1]->addTroop(troopCount);

		break;
	} while(true);
}

void Game::endTurn(Player* p) {
	setTitle("Drawing a Card");

	Hand* h = p->getHand();
    //if it was, the player gets a card and sets value back to false
	h->addCard(*deck);
	terrConquered = false;

	cout << "You drew one card from the deck and pulled " << h->getLastCardName()
	     << ". You now have " << h->size() << (h->size() == 1 ? " card." : " cards.");

	pause();
}

int Game::roll() {
	return (rand() % 5) + 1;
}

void Game::setTitle(string title) {
	text[0] = title;

	Display::clear();
	Display::setTextColor(gBlack);
	cout << Display::distribute(text, align);
	Display::resetTextColor();
	cout << endl;
}

void Game::pause() {
	cout << endl << endl << "Press any key to continue to the next step...";

	_getch();
}

vector<Territory*> Game::playerOwns(Player *p) {
	vector<Territory*> ret;

	for (int i = 0; i < territories.size(); ++i) {
		if (territories[i]->getOwner()->getColor() == p->getColor()) {
			ret.push_back(territories[i]);
		}
	}

	return ret;
}

void Game::initialTerrDistribution()
{
	vector<int> numTroops(players.size());
	int initDistribution = (deck->size() / players.size());
	int remainder = territories.size() % players.size();
	int initRemainder = remainder;
	int num = rand() % players.size();

	for(int i=0; i<numTroops.size(); i++)
		numTroops[i] = initDistribution;
	for(int i=numTroops.size()-1; remainder > 0; i--) {
		numTroops[i]++;
		remainder--;
	}

	for(int i=0; i<territories.size(); i++) {
		while(numTroops[num] == 0)
			num = rand() % players.size();
		
			territories[i]->addTroop();
			territories[i]->setOwner(&players[num]);
			numTroops[num]--;
	}
}
void Game::initialTroopDistribution()
{
	vector<int> numTroops(players.size());
	bool continuePlacement = true;
	int terrNum;
	string answer = "";
	bool validAnswer = false;
	int remainder = territories.size() % players.size();

	for(int i=0; i<numTroops.size(); i++)
		numTroops[i] = INITIAL_TROOPS[players.size()-2];
	for(int i=numTroops.size()-1; remainder > 0; i--) {
		numTroops[i]--;
		remainder--;
	}

	while(continuePlacement) {
		for(int j=0; j<players.size(); j++) {
			if(numTroops[j] == 0)
				continue;
			vector<Territory*> terrRet = playerOwns(&players[j]);
			Display::clear();
			setTitle("Initial Troop Placement");
			for(int i = 0; i < terrRet.size(); i++) {
				cout << i+1 << ". ";
				
				if (i + 1 < 10) {
					cout << " ";
				}

				cout << terrRet[i]->getName() << "(Troops: " << terrRet[i]->getNumTroops() << ")" << endl;
			}
			cout << endl;
			Display::setTextColor(players[j].getColor());
			cout << players[j].getName() << ", choose a territory to reinforce: ";
			Display::resetTextColor();

			while(!validAnswer) {
				cin >> answer;
				terrNum = atoi(answer.c_str());
				if(terrNum <= terrRet.size() && terrNum > 0)
					validAnswer = true;
				else {
					Display::setTextColor(players[j].getColor());
					cout << "invalid answer" << endl;
					cout << players[j].getName() << ", choose a territory to reinforce: ";
					Display::resetTextColor();
				}
			}
			validAnswer = false;
			terrRet[terrNum-1]->addTroop();
			numTroops[j]--;
		}
		int i=0;
		for(i; i<players.size(); i++) {
			if(numTroops[i] != 0)
				break;
		}
		if(i==players.size() && numTroops[i-1] == 0)
			continuePlacement = false;
	}
}