/* 
  Author:  Suite Team [Jake Gearhart, Jesse Ficter, Oliver Spryn]
  Course:  COMP 220, Computer Programming II 
  Date:    23 September 2012 
  Description:  This file contains configuration which is used
                throughout the program, and provides a quick
				place to reference and update these config values.
*/

#include <string>
#include "Config.h"

using std::string;

const string Config::GAME_NAME = "  ____  _            _    _            _    \n"
" |  _ \\| |          | |  (_)          | |   \n"
" | |_) | | __ _  ___| | ___  __ _  ___| | __\n"
" |  _ <| |/ _` |/ __| |/ / |/ _` |/ __| |/ /\n"
" | |_) | | (_| | (__|   <| | (_| | (__|   < \n"
" |____/|_|\\__,_|\\___|_|\\_\\ |\\__,_|\\___|_|\\_\\\n"
"     /\\  | | | |        _/ | |              \n"
"    /  \\ | |_| |_ __ _ |__/| | __           \n"
"   / /\\ \\| __| __/ _` |/ __| |/ /           \n"
"  / ____ \\ |_| || (_| | (__|   <            \n"
" /_/    \\_\\__|\\__\\__,_|\\___|_|\\_\\           \n"
"                                            \n"
"                                            \n";

const string Config::INSTRUCTIONS =
	"Here are the rules of Blackjack:\nThe goal is to get closer to 21 than the dealer without going over.\n"
	"The dealer wins in the event of ties unless you got to the value with less cards"
	"The cards all have point values that add together, numbers are equal to their \nnumber, face cards are equal"
	"to 10, and Aces equal 1 or 11 depending on which is more favorable in your situation"
	" You then enter in the number of chips\nyou will wager on the round"
	" To play the game the dealer first deals himself two cards, and you see only the first card"
	" Then he gives himself cards until he is\nover 17, then it is your turn"
	" On your turn you are given two cards, and then youcan enter what you want to do next"
	"\nenter 'hit' to take another card\nenter 'stand' to stop at your current value"
	"\nYou can also enter 'surrender before you take more cards to give up and\nonly lose half the bet"
	" If you enter anything else the end automatically ends"
	" If you get over 1 million chips you win, or you can quit after a round or you lose if you are out of chips"
	" Beware the dealer can be tricky...\n";

const string Config::WELCOME =
	"Welcome to Blackjack Attack! The game where the dealer is everywhere\nand you could be robbed at any time!\n";

const int Config::CARD_HEIGHT = 8;
const int Config::CARD_WIDTH = 9;
const int Config::CONSOLE_HEIGHT = 25;
const int Config::CONSOLE_WIDTH = 80;
const int Config::DEFAULT_CONSOLE_COLOR = 7;
const string Config::ERROR_OUT_OF_BOUNDS_SUIT_VALUE = "An out of bounds suit value was entered";
const int Config::MINIMUM_BETTING_VALUES[3] = {5, 25, 100};
const string Config::MINIMUM_BETTING_TEXT = "betting chips";
const string Config::MINIMUM_BETTING_VALUE_PROMPT_TEXT = "Enter a number";