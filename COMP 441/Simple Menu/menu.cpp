
#include "menu.h"

Menu::Menu()
{
	selectedItem = -1;	//nothing return
	menuItemFont = new TextDX();
	menuHeadingFont = new TextDX();
}

void Menu::initialize(Graphics *g, Input *i)
{
	menuHeading ="Test Menu";
	highlightColor = graphicsNS::RED;
	normalColor = graphicsNS::WHITE;
	menuAnchor = D3DXVECTOR2(270,10);
	input = i;
	verticalOffset = 30;
	linePtr = 0;
	selectedItem = -1;
	graphics = g;
	menuItemFont = new TextDX();
	menuHeadingFont = new TextDX();
	menuItemFontHighlight = new TextDX();
	if(menuItemFont->initialize(graphics, 15, true, false, "Calibri") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menuItem font"));
	if(menuItemFontHighlight->initialize(graphics, 18, true, false, "Calibri") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menuItem font"));
	if(menuHeadingFont->initialize(graphics, 25, true, false, "Calibri") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menuHeading font"));
	menuHeadingFont->setFontColor(normalColor);
	menuItemFont->setFontColor(normalColor);
	menuItemFontHighlight->setFontColor(highlightColor);
	upDepressedLastFrame = false;
	downDepressedLastFrame = false;

	down = false;
	oldLeftPos = menuAnchor.x;
	parentSelected = 0;
	leftPos = 200;
	rightPos = 400;
	showMenu = -1;

	srand(time(0));

	level1.push_back("Options");
	level1.push_back("Enable SoundFX");
	level1.push_back("I'm feeling lucky");

	level2.resize(2);

	level2[0].push_back("Amazing Value");
	level2[0].push_back("Same Great Price");

	level2[1].push_back("On");
	level2[1].push_back("Off");

	/*
	vector<string> level21;
	level21.push_back("Amazing Value");
	level21.push_back("Same Great Price");

	vector<string> level22;
	level22.push_back("On");
	level22.push_back("Off");

	level2.push_back(level21);
	level2.push_back(level22);*/
}

void Menu::update()
{
	if (!down) {
		if (input->isKeyDown(VK_UP))
		{
			linePtr--;
			down = true;
		}
		if (input->isKeyDown(VK_DOWN))
		{
			linePtr++;
			down = true;
		}

		if (input->isKeyDown(VK_LEFT))
		{
			showMenu = -1;
			menuAnchor.x = oldLeftPos;
			linePtr = 0;
		}
		if (linePtr > 2) linePtr = 0;
		if (linePtr < 0) linePtr = 2;

		if (input->isKeyDown(VK_RETURN)) {
			selectedItem = linePtr;

			if (showMenu == -1) {
				linePtr = 0;
			}

			showMenu = linePtr;
		} else {
			selectedItem = -1;
		}
	} else {
		if (!input->isKeyDown(VK_UP) && !input->isKeyDown(VK_DOWN))
			down = false;
	}
	
}

void Menu::displayMenu()
{
	int foo = verticalOffset;
	menuHeadingFont->print(menuHeading, menuAnchor.x, menuAnchor.y);

	for (int i = 0; i < level1.size(); ++i) {
		if (linePtr == i && showMenu == -1) {
			menuItemFontHighlight->print(level1[i], menuAnchor.x, menuAnchor.y+foo);

			if (level1[i] == "I'm feeling lucky") {
				parentSelected = rand() % 2;
				selectedItem = 0;
			} else {
				parentSelected = i;
			}
		} else {
			menuItemFont->print(level1[i], menuAnchor.x, menuAnchor.y+foo);
		}

		foo = (i + 2) * verticalOffset;
	}

	if (showMenu != -1) {
		menuAnchor.x = leftPos;
		foo = verticalOffset;

		for (int i = 0; i < level2[parentSelected].size(); ++i) {
			if (linePtr == i) {
				menuItemFontHighlight->print(level2[parentSelected][i], rightPos, menuAnchor.y+foo);
			} else {
				menuItemFont->print(level2[parentSelected][i], rightPos, menuAnchor.y+foo);
			}

			foo = (i + 2) * verticalOffset;
		}
	}
}

void Menu::displaySub() {
	int foo = verticalOffset;
	int selected = 0;
	menuAnchor.x = leftPos;
	menuHeadingFont->print(menuHeading, menuAnchor.x, menuAnchor.y);

	for (int i = 0; i < level1.size(); ++i) {
		if (linePtr == i) {
			menuItemFontHighlight->print(level1[i], menuAnchor.x, menuAnchor.y+foo);
			selected = i;
		} else {
			menuItemFont->print(level1[i], menuAnchor.x, menuAnchor.y+foo);
		}

		foo = (i + 2) * verticalOffset;
	}

	foo = verticalOffset;

	for (int i = 0; i < level2[selected].size(); ++i) {
		if (linePtr == i) {
			menuItemFontHighlight->print(level2[selected][i], rightPos, menuAnchor.y+foo);
			selected = i;
		} else {
			menuItemFont->print(level2[selected][i], rightPos, menuAnchor.y+foo);
		}

		foo = (i + 2) * verticalOffset;
	}
}