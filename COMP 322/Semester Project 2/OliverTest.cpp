/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013
*   Description: This file implements the OliverTest file which is used to test the game  
*/


#include "OliverTest.h"

OliverTest::OliverTest() {
}

OliverTest::~OliverTest() {
	releaseAll();
}

void OliverTest::ai() {

}

void OliverTest::collisions() {
	D3DXVECTOR2 v;
	
	//if (t->collidesWithTop(*l, v)) {
	//	dir = t->getDirection();
	//	l->bounce(v, *l);
	//}
}

void callback(ClickData<Tile> d) {
	MessageBox(NULL, "Hi", "Error", MB_OK);
}

void OliverTest::initialize(HWND hwnd) {
	fireDeg1 = 90;
	fireDeg2 = 270;
	Game::initialize(hwnd);
	graphics->setBackColor(SETCOLOR_ARGB(255, 0, 0, 0));
	
	l = new Laser(this, graphics, Laser::COLOR_RED);
	l->initialize();
	l->setSelfDestructMethod(Laser::TIMER_DESTROY, 5000);

	l2 = new Laser(this, graphics, Laser::COLOR_RED);
	l2->initialize();
	l2->setSelfDestructMethod(Laser::TIMER_DESTROY, 5000);

//Create the GridParser
	this->kp = new KhetParser<Tile>("config\\classic.txt");

//Create the Grid
	this->g = new Grid<Tile, 10, 8>(this, graphics);
	this->g->setBkg("pictures\\GameBoard.png");
	this->g->initialize(this->kp);

	//t = new Tile(this, graphics);
	//t->setGraphic("pictures\\tile-white.jpg");
	//t->initialize();
	//t->setX(150.0f);
	//t->setY(300.0f);

	//t2 = new Tile(this, graphics);
	//t2->setGraphic("pictures\\tile-white.jpg");
	//t2->initialize();
	//t2->setX(150.0f);
	//t2->setY(200.0f);

	/*for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			tiles[i][j] = new Tile(this, graphics);
			tiles[i][j]->setGraphic("pictures\\tile.jpg");
			tiles[i][j]->initialize();
			tiles[i][j]->setX(j*48.0f);
			tiles[i][j]->setY(i*48.0f);
		}
	}*/
}

void OliverTest::releaseAll() {
	Game::releaseAll();
}

void OliverTest::render() {
	graphics->spriteBegin();
	//t->draw();
	//t2->draw();
	/*
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			tiles[i][j]->draw();
		}
	}*/
	this->g->draw();
	l->draw();
	l2->draw();
	
    graphics->spriteEnd();   
}

void OliverTest::resetAll() {
	Game::resetAll();
}

void OliverTest::update() {
	//t->update(frameTime);
	//t2->update(frameTime);
	/*for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			tiles[i][j]->update(frameTime);
		}
	}*/
	l->fireDeg(608.0f, 426.0f, fireDeg1);
	l2->fireDeg(32.0f, 64.0f, fireDeg2);

	l->update(frameTime);
	l2->update(frameTime);

	this->g->update(frameTime);
}