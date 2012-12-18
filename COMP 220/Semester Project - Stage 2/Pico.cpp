/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         15 October 2012 
 * Description:  This is the class which will be used to
                 layout the editor and then display the
				 interactive content in the center of the
				 screen
*/ 


#include <iostream>
#include <string>
#include <Windows.h>

#include "CentralizeParametersInvalidException.h"
#include "Document.h"
#include "Pico.h"
#include "TextDisplayConfigurationException.h"

using std::cout;
using std::endl;
using std::string;

/**
 * CONSTRUCTOR
 *
 * This function is simply responsible for laying out the header of the editor
 * and initializing the Document class which contains the actual document and
 * the rollback buffers.
 * 
 * @access public
 * @param  Document d An instance of the document class containing the document to edit
 * @return void
*/

Pico::Pico(Document d) : document(d) {
	this->refresh(-1, 1);
}

void Pico::refresh(int bufferIndex, int startingLine) {
//Output the header
	//vector<string> text;
	//text.push_back(Pico::EDITOR_NAME);
	//text.push_back(this->document.getDocumentName());
	//text.push_back(Pico::MOD_NO);
	
	//vector<char> align;
	//align.push_back('L');
	//align.push_back('C');
	//align.push_back('R');

	//try {
	//	this->highlightText(this->centralize(text, align));
	//	cout << endl;
	//} catch (CentralizeParametersInvalidException e) {
	//	cout << e;
	//}

//Output the document
	try {
		cout << this->document.display(bufferIndex, startingLine);
	} catch (TextDisplayConfigurationException e) {
		cout << e;
	}

//Display the toolbar
	//cout << endl;
//
//	vector<string> tools;
//	tools.push_back("^Z Undo");
//	tools.push_back("^Y Redo");
//	tools.push_back("^F Forward");
//	tools.push_back("^B Backward");
//	tools.push_back("^R Refresh");

//	vector<char> alignTools;
//	alignTools.push_back('L');
//	alignTools.push_back('L');
//	alignTools.push_back('L');
//	alignTools.push_back('L');
//	alignTools.push_back('L');


//	try {
//		cout << this->centralize(tools, alignTools);
//	} catch (CentralizeParametersInvalidException e) {
//		cout << e;
//	}

//Enable the editing capibilities
	this->document.enableEditing();
}

/**
 * This function will take a vector of strings and lay them out such that each
 * string will have its own "cell" in an evenly-spaced, invisible table that
 * stretches the length of the console window.
 *
 * For example, if these strings are given:
 *  - one
 *  - two
 *  - three
 *  - four
 *
 * they will be laid out like this (except without the table border, which is 
 * show here to demonstrate this function's formatting capibilities):
 *
 * +------------------+------------------+------------------+-----------------+
 * |one               |two               |three             |four             |
 * +------------------+------------------+------------------+-----------------+
 *
 * The align parameter will accept a vector of characters, where each character
 * may have one of the following values:
 *  - L = align left
 *  - C = align center
 *  - R = align right
 *
 * The string of text is matched to the associated align character by its index
 * in each of the vectors.
 *
 * @access public
 * @param  vector<string>                       text  A vector of strings containing text to be aligned
 * @param  vector<char>                         align A vector of characters symbolizing the string's alignment within the respective "cell"
 * @return string                               ret   A string formatted to the parameter's specifications
 * @throws CentralizeParametersInvalidException       Encountered if parameter vector sizes do not match or if an invalid character appears in the align vector
*/

string Pico::centralize(vector<string> text, vector<char> align) {
	int length = text.size();
	string ret = "";
	
//Does the size of each vector parameter match?
	if (text.size() != align.size()) {
		string error = "The number of strings in the text parameter (";
		error += text.size();
		error += ") does not match the number of characters in the align parameter (";
		error += align.size();
		error += ").";

		throw CentralizeParametersInvalidException(error);
	}

//Calculate the number of characters we can allot per cell with the given input
	int cellW = static_cast<int>(floor(static_cast<double>(Pico::CONSOLE_WIDTH) / static_cast<double>(length)));
	int extra = Pico::CONSOLE_WIDTH - (cellW * length);
	int leftW = 0;
	int rightW = 0;
	
//Print out each "cell"
	for (int i = 0; i < length; i++) {
		switch(align[i]) {
			case 'L' : 
				ret += text[i];

			//Add any padding needed to the right side of the text
				rightW = 0;
				rightW = cellW - text[i].length();

				for (int k = 0; k < rightW; k++) {
					ret += " ";
				}

			//Usually not all cells will have an even amount of space, so in the final iterations of this loop
			//output an additional space in the last few cells to ensure the the returned string is still
			//Pico::CONSOLE_WIDTH characters wide
				if (extra + i >= length) {
					ret += " ";
				}

				break;

			case 'C' : 
			//Add any padding needed to the left side of the text
				leftW = 0;
				leftW = static_cast<int>(floor(static_cast<double>(cellW - text[i].length()) / 2.0));

				for (int j = 0; j < leftW; j++) {
					ret += " ";
				}

				ret += text[i];

			//Add any padding needed to the right side of the text
				rightW = 0;
				rightW = static_cast<int>(ceil(static_cast<double>(cellW - text[i].length()) / 2.0));

				for (int k = 0; k < rightW; k++) {
					ret += " ";
				}

			//Usually not all cells will have an even amount of space, so in the final iterations of this loop
			//output an additional space in the last few cells to ensure the the returned string is still
			//Pico::CONSOLE_WIDTH characters wide
				if (extra + i >= length) {
					ret += " ";
				}

				break;

			case 'R' : 
			//Usually not all cells will have an even amount of space, so in the final iterations of this loop
			//output an additional space in the last few cells to ensure the the returned string is still
			//Pico::CONSOLE_WIDTH characters wide
				if (extra + i >= length) {
					ret += " ";
				}

			//Add any padding needed to the right side of the text
				leftW = 0;
				leftW = cellW - text[i].length();

				for (int j = 0; j < leftW; j++) {
					ret += " ";
				}

				ret += text[i];
				break;

			default : 
				string error = "An invalid align type wan encountered: ";
				error += align[i];
				error += ". Valid align types include: L (left), C (center), or R (right).";

				throw CentralizeParametersInvalidException(error);
				break;
		}
	}
	
	return ret;
}

void Pico::highlightText(string text) {
	HANDLE cHandle;
	cHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(cHandle, Pico::HIGHLIGHT_COLOR);
	cout << text;
	SetConsoleTextAttribute(cHandle, Pico::DEFAULT_CONSOLE_COLOR);
}

const string Pico::EDITOR_NAME = "  GCC Pico 0.2.0";
const string Pico::MOD = "Modified";
const string Pico::MOD_NO = "";