/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         15 October 2012 
 * Description:  This is the class which will be used to
                 layout the editor and then display the
				 interactive content in the center of the
				 screen
*/ 


#ifndef PICO_H
#define PICO_H

#include <string>
#include <vector>

#include "Document.h"

using std::string;
using std::vector;

class Pico {
public:
	Pico(Document d);

	string centralize(vector<string> text, vector<char> align);
	void highlightText(string text);
	void refresh(int bufferIndex, int startingLine);

	Document document;

	static const int APP_TOOLS_HEIGHT = 4;
	static const int CONSOLE_HEIGHT = 25;
	static const int CONSOLE_WIDTH = 80;
	static const int DEFAULT_CONSOLE_COLOR = 7;
	static const int DOCUMENT_HEIGHT = 25;
	static const int EDITOR_BOTTOM = 22;
	static const int EDITOR_TOP = 0;
	static const string EDITOR_NAME;
	static const int HIGHLIGHT_COLOR = 112;
	static const string MOD;
	static const string MOD_NO;
};

struct Coordinate {
  int x;
  int y;
};

#endif