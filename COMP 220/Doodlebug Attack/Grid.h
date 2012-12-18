/* 
  Author:  Oliver Spryn 
  Course:  COMP 220, Computer Programming II 
  Date:    Nov 30 2012 
  Description:  This is the class definition file for the visual space which the organisms may move. It
                also will move the organisms and control when the they die and eat, based on the stored 
				informtion in the class.
*/

#include "Organism.h"

class Grid {
public : 
	Grid();

private : 
	Organism* organisms[400];

	void refersh();
	void resetTextColor();
	void textColor(int color);
};

enum colors {
	black = 0,
	darkBlue = 1,
	darkGreen = 2,
	darkAqua, darkCyan = 3,
	darkRed = 4,
	darkPurple = 5, darkPink = 5, darkMagenta = 5,
	darkYellow = 6,
	darkWhite = 7,
	gray = 8,
	blue = 9,
	green = 10,
	aqua = 11, cyan = 11,
	red = 12,
	purple = 13, pink = 13, magenta = 13,
	yellow = 14,
	white = 15
};