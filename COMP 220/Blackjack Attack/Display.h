#include <string>
#include <vector>
#include"Card.h"

using std::string;
using std::vector;

class Display {
public:
	Display();
	static void center(string text, int avaliableWidth);
	static void coloredText(int text, int color);
	static void coloredText(string text, int color);
	static void displayCard(vector<Card> hand, bool isDealer);
	static void resetTextColor();
	static void setTextColor(int color);
	static string setw(int width);
	static void userInfo(int chipValue, int playerScore, int dealerScore, int round);
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