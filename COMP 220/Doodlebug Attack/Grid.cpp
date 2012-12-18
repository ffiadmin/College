/* 
  Author:  Oliver Spryn 
  Course:  COMP 220, Computer Programming II 
  Date:    Nov 30 2012 
  Description:  This is the class definition file for the visual space which the organisms may move. It
                also will move the organisms and control when the they die and eat, based on the stored 
				informtion in the class.
*/

#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#include <Windows.h>

#include "Ant.h"
#include "Config.h"
#include "DoodleBug.h"
#include "Grid.h"

using std::cin;
using std::cout;
using std::endl;
using std::random_shuffle;
using std::swap;
using std::time;
using std::vector;

Grid::Grid() {
	int position, breedz;

	for (int i = 0; i < Config::DOODLEBUG_INIT; i++) {
		organisms[i] = new DoodleBug;
	}

	for (int j = Config::DOODLEBUG_INIT; j < Config::DOODLEBUG_INIT + Config::ANTS_INIT; j++) {
		organisms[j] = new Ant;
	}

	for (int k = Config::DOODLEBUG_INIT + Config::ANTS_INIT; k < Config::ROWS * Config::COLUMNS; k++) {
		organisms[k] = new Organism;
	}

	srand(time(NULL));
	random_shuffle(organisms, organisms + 400);

	do {
		this->refersh();
		cin.ignore();

		for(int i = 0; i < Config::ROWS * Config::COLUMNS; i++) {
			position = organisms[i]->move(i);
			
			if (position >= 0 && position < 400) {
				if (organisms[i]->type() == 2 && organisms[i]->movesSinceEating % 3 == 0) {
					organisms[i] = new Organism;
				} else {
					if (organisms[i]->type() == 1 && organisms[i]->movesSinceBreeding % 3 == 0) {
						breedz = organisms[i]->breed(i);

						if (breedz >= 0 && breedz < 400 && organisms[breedz]->type() == 0) {
							organisms[breedz] = new Ant;
						}
					}

					if (organisms[i]->type() == 2 && organisms[i]->movesSinceBreeding % 8 == 0) {
						breedz = organisms[i]->breed(i);

						if (breedz >= 0 && breedz < 400 && organisms[breedz]->type() == 0) {
							organisms[breedz] = new DoodleBug;
						}
					}

					if (organisms[position]->type() <= organisms[i]->type()) {
						swap(organisms[i], organisms[position]);
					} else {
						//swap(organisms[i], organisms[position]);
						//organisms[i] = new Organism;

					}
				}
			}
		}
	} while(true);
}

void Grid::refersh() {
	system("CLS");

	for(int l = 0; l < Config::ROWS; l++) {
		this->textColor(darkAqua);
		cout << "+";

		for(int m = 0; m < Config::COLUMNS; m++) {
			cout << "-+";
		}

		cout << endl << "|";

		for(int n = 0; n < Config::COLUMNS; n++) {
			switch(organisms[Config::COLUMNS * l + n]->shortType()) {
				case 'A' : 
					this->textColor(red);
					cout << "A";
					break;

				case 'D' : 
					this->textColor(yellow);
					cout << "D";
					break;

				case 'O' : 
					cout << " ";
					break;
			}
			
			this->textColor(darkAqua);
			cout << "|";
		}

		cout << endl;
	}

	cout << "+";

	for(int o = 0; o < Config::COLUMNS; o++) {
		cout << "-+";
	}

	cout << endl;
}

void Grid::textColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}

void Grid::resetTextColor() {
	this->textColor(darkWhite);
}