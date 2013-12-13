/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the Grid class which can be ported to other games easily  
*/

#ifndef GRID_H
#define GRID_H

#include "game.h"
#include "gameError.h"
#include "graphics.h"
#include "GridParser.h"
#include "image.h"
#include "textureManager.h"
#include "Tile.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace gridNS {
	const int HEIGHT  = 64;
	const int WIDTH   = 64;
}

template <class T>
struct ClickData {
	ClickData() { };
	int x, y;
	T* tile;
};

template <class T, int X, int Y>
class Grid {
typedef void(*FPtr)(ClickData<T>);

private : 
	Image background;
	TextureManager backgroundTM;
	Game* game;
	Graphics* graphics;

	char *bkgSource;
	FPtr callback;
	Input* input;
	vector<vector<T*>> pieces;
	int x;
	int y;

public : 
	Grid(Game* game, Graphics* graphics) : bkgSource('\0'), game(game), graphics(graphics) {
		input = game->getInput();
        this->x = 0;
		this->y = 0;
		this->pieces.resize(X);

		for (int i = 0; i < X; ++i) {
			this->pieces[i].resize(Y);
		}
	}

	~Grid() {
		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				delete this->pieces[i][j];
			}
		}

		delete this->bkgSource;
	}

	void draw() {
		if (this->bkgSource != '\0') {
			this->background.draw();
		}

		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				this->pieces[i][j]->draw();
			}
		}
	}

	T* getAt(int x, int y) {
		return this->pieces[x][y];
	}

	vector<vector<T*>>* getT() {
		return &this->pieces;
	}

	void initialize(GridParser<T>* g) {
	//Initialize the background
		if (this->bkgSource != '\0') {
			int height = Y * gridNS::HEIGHT;
			int width = X * gridNS::WIDTH;

			if (!this->backgroundTM.initialize(this->graphics, this->bkgSource))
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing the grid background texture"));

			if (!this->background.initialize(this->graphics, width, height, 0, &this->backgroundTM))
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing the grid backgound"));

			this->background.setX(this->x);
			this->background.setY(this->y);
		}
		
	//Initialize the tiles
		T* current;

		for (int i = 0; i < Y; ++i) {
			for (int j = 0; j < X; ++j) {
				this->pieces[j][i] = g->next(this->game, this->graphics);
				this->pieces[j][i]->initialize();
				this->pieces[j][i]->setX(this->x + i * gridNS::WIDTH);
				this->pieces[j][i]->setY(this->y + j * gridNS::HEIGHT);
			}
		}

		for (int i = 0; i < Y; ++i) {
			for (int j = 0; j < X; ++j) {
				this->pieces[j][i]->setOrientation(g->configureDir());
			}
		}
	}

	void setBkg(char* source) {
		this->bkgSource = source;
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	void swap(int fromX, int fromY, int toX, int toY) {
		T* temp = this->pieces[fromX][fromY];
		
		this->pieces[fromX][fromY] = this->pieces[toX][toY];
		this->pieces[toX][toY] = temp;
	}

	void swap(T* from, T* to) {
		T temp = from;

		from = to;
		to = temp;
	}

	void update(float frameTime) {
	//Background update
		if (this->bkgSource != '\0') {
			this->background.setX(this->x);
			this->background.setY(this->y);
			this->background.update(frameTime);
		}

	//Update the T objects
		T* current;

		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				current = this->pieces[i][j];
				current->setX(this->x + i * gridNS::WIDTH);
				current->setY(this->y + j * gridNS::HEIGHT);
				current->update(frameTime);
			}
		}

	//Check for clicks
		/*if (this->input->getMouseLButton()) {
			int mouseX = this->input->getMouseX();
			int mouseY = this->input->getMouseY();

			int height = Y * gridNS::HEIGHT;
			int width = X * gridNS::WIDTH;

		//What tile was clicked on?
			if (mouseX >= this->x && mouseX <= width &&
				mouseY >= this->y && mouseY <= height) {
					ClickData<T> d;
					d.x = mouseX / gridNS::WIDTH;
					d.y = mouseY / gridNS::HEIGHT;
					d.tile = this->pieces[d.x][d.y];

					this->callback(d);
			}
		}*/
	}
};

#endif