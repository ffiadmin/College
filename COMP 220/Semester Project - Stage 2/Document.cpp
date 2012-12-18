/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         15 October 2012 
 * Description:  This class loads the text file and adds
                 all of the interactivity to the content,
				 such as entry and deletion of text, undos,
				 and saves.
*/ 


#include <conio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>

#include "Document.h"
#include "FileOpenFailureException.h"
#include "Pico.h"
#include "TextDisplayConfigurationException.h"

using std::cin;
using std::cout;
using std::fstream;
using std::ofstream;
using std::string;
using std::stringstream;

/**
 * CONSTRUCTOR
 *
 * This function will open and store the contents of the file based on
 * the given parameter. The given file name will also stored for later
 * access.
 * 
 * @access public
 * @param  string                   document The name or address of the file to open
 * @return void
 * @throws FileOpenFailureException          Occurs if the provided parameter does not contain a valid address to a file
*/

Document::Document(string document) : documentName(document) {
	this->openFile();
}

void Document::enableEditing() {
	char test, trash = 0;
	Coordinate cursor = {0, Pico::EDITOR_TOP};
	COORD coord;
	coord.X = cursor.x;
	coord.Y = cursor.y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	do {
		vector<data> docConstraits = this->countCharacters(-1);

		if (GetAsyncKeyState(VK_UP)) {
			if (cursor.y > Pico::EDITOR_TOP) {
				int end = docConstraits[cursor.y - 1 - Pico::EDITOR_TOP].charEnd - docConstraits[cursor.y - 1 - Pico::EDITOR_TOP].charStart;
				cursor.y--;
				
				if (end < cursor.x) {
					cursor.x = end;
				}
			}
		} else if (GetAsyncKeyState(VK_DOWN)) {
			if (cursor.y < docConstraits.size() - 1 + Pico::EDITOR_TOP) {
				int end = docConstraits[cursor.y + 1 - Pico::EDITOR_TOP].charEnd - docConstraits[cursor.y + 1 - Pico::EDITOR_TOP].charStart;
				cursor.y++;

				if (end < cursor.x) {
					cursor.x = end;
				}
			}
		} else if (GetAsyncKeyState(VK_LEFT)) {
			if (cursor.x > 0) {
				cursor.x--;
			}
		} else if (GetAsyncKeyState(VK_RIGHT)) {
			int end = docConstraits[cursor.y - Pico::EDITOR_TOP].charEnd - docConstraits[cursor.y - Pico::EDITOR_TOP].charStart;

			if (cursor.x < Pico::CONSOLE_WIDTH && cursor.x < end) {
				cursor.x++;
			}

		} else if (GetAsyncKeyState(0x70)) {
			this->undo();
		} else if (GetAsyncKeyState(0x71)) {
			this->save();
			break;
		} else if (GetAsyncKeyState(0x72)) {
			this->saveAs();
			break;
		} else if (GetAsyncKeyState(VK_BACK)) {
			cout << "\a";

			this->undo();
			
			COORD coord;
			coord.X = 0;
			coord.Y = 0;
	
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		} else if (GetAsyncKeyState(VK_DELETE)) {
			this->remove(cursor.y, cursor.x - 1);
		} else if (GetAsyncKeyState(VK_RETURN)) {
			cout << "\a";
			this->undo();

			COORD coord;
			coord.X = 0;
			coord.Y = 0;
	
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		} else {
			if (!GetAsyncKeyState(VK_LCONTROL) && !GetAsyncKeyState(VK_RCONTROL) && !GetAsyncKeyState(VK_RETURN)) {
				test = _getch();

				if (test == 0 || test == -32) {
					trash = _getch();
				} else {
					this->add(test, cursor.y, cursor.x);

					if (cursor.x < Pico::CONSOLE_WIDTH) {
						cursor.x++;
					}
				}
			}
		}

		COORD coord;
		coord.X = cursor.x;
		coord.Y = cursor.y;
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		Sleep(100);
		
		this->display(-1, 1);
	} while (true);

	system("CLS");
}

void Document::openFile() {
//Open the file
	fstream fin;
	fin.open(this->documentName);

//Check if file opening was successful
	if (fin.fail()) {
		string error = "The provided file could not be found for opening: ";
		error += this->documentName;
		error += ".";

		throw FileOpenFailureException(error);
	}

//Read the file and store it in a buffer
	char next;
	string buffer = "";

	while (fin.get(next) && !fin.eof()) {
		buffer += next;
	}

	this->actionBuffer.push_back(buffer);
	fin.close();
}

void Document::save() {
	ofstream fin;
	fin.open(this->documentName);
	fin << this->actionBuffer[this->actionBuffer.size() - 1];
	fin.close();
}

void Document::saveAs() {
	string name = "";

	system("CLS");
	cout << "Enter the name of the file: ";
	cin >> name;

	ofstream fin;
	fin.open(name);
	fin << this->actionBuffer[this->actionBuffer.size() - 1];
	fin.close();

	cout << "Saved" << std::endl;
}

/**
 * Provide read-only access to the private "documentName" variable.
 * 
 * @access public
 * @return string documentName The name of the document provided during class instantiation
*/

string Document::getDocumentName() {
	return this->documentName;
}

/**
 * Return a vector of vectors containing the line number and index
 * of the character starting on and ending on each line within a 
 * given index of the buffer.
 * 
 * @access private
 * @param  int          bufferIndex The index of the buffer value to obtain the number of characters
 * @return vector<data> ret         A vector of the "data" type which will contain {line number, # of first char, # of last char}
*/

vector<data> Document::countCharacters(int bufferIndex) {
	vector<data> ret;

	string buffer = "";
	int lineLen = 0;
	int lineNumber = 0;

//Obtain the data from the buffer
	if (bufferIndex > static_cast<int>(this->actionBuffer.size() - 1) || bufferIndex < 0) {
		buffer = this->actionBuffer[this->actionBuffer.size() - 1];
	} else {
		buffer = this->actionBuffer[bufferIndex];
	}

//Evaluate each character at a time
	for (int i = 0; i < static_cast<int>(buffer.length()); i++) {
		lineLen++;

	//Increase the line number at the beginning of a line...
		if (lineLen == 1 || lineLen == Pico::CONSOLE_WIDTH + 1) {
			lineNumber++;
			lineLen = 1;

		//Push the position of the character at the end of the previous line onto the return vector
			if (lineNumber > 1) {
				ret[lineNumber - 2].charEnd = i - 1;
			}
			
		//We've counted our way to the end of this line, push in onto the return vector
			data values = {lineNumber, i, 0};
			ret.push_back(values);
		}

	//... or reset the line counter at each \n for further processing in the next loop
		if (buffer.at(i) == '\n') {
			lineLen = 0;
		}
	}

//Push the position of the character at the end of the very last line onto the return vector
	ret[lineNumber - 1].charEnd = static_cast<int>(buffer.length() - 1);
	
	return ret;
}

/**
 * Get the number of characters in the requested buffer. This 
 * function will count all whitespace as characters, which
 * will esentially consider the entire text file to be one block
 * of text.
 *
 * If the given index is out of bounds, the number of lines in 
 * the  most recent  buffer value is returned.
 *
 * NOTE: This private function CANNOT be used to generate a word
 * or character count. This is a low-level function which is 
 * strictly designed to serve technical purposes in conjunction 
 * with the getNumberOfLinesInBuffer() function.
 * 
 * @access private
 * @param  int    bufferIndex     The index of the buffer value to obtain the number of characters
 * @return void
*/

int Document::countCharactersWS(int bufferIndex) {
	string buffer = "";
	int bufferLen = 0;
	int lineNumber = 0;

//Obtain the data from the buffer
	if (bufferIndex > static_cast<int>(this->actionBuffer.size() - 1) || bufferIndex < 0) {
		buffer = this->actionBuffer[this->actionBuffer.size() - 1];
	} else {
		buffer = this->actionBuffer[bufferIndex];
	}
	
//Evaluate each character at a time
	for (int i = 0; i < static_cast<int>(buffer.length()); i++) {
	//Non-new line characters are easy!
		if (buffer.at(i) != '\n') {
			bufferLen++;

		//Account for a new line when we read the first character in the line
			if (bufferLen % Pico::CONSOLE_WIDTH == 0) {
				lineNumber++;
			}
		} else {
		//This is an empty line, add Pico::CONSOLE_WIDTH characters to this value
			if (bufferLen % Pico::CONSOLE_WIDTH == 0) {
				bufferLen += Pico::CONSOLE_WIDTH;
		//Add the number of characters that should consume the whitespace on the end of a line with a \n
			} else {
				bufferLen += Pico::CONSOLE_WIDTH - (bufferLen % Pico::CONSOLE_WIDTH);
			}
		}
	}
	
	return bufferLen;
}

/**
 * Get the number of lines contained within a certain index in the
 * buffer. If the given index is out of bounds, the number of lines
 * in the most recent buffer value is returned.
 * 
 * @access private
 * @param  int    bufferIndex The index of the buffer value to obtain the number of lines
 * @return int    lines       The number of lines in the provided buffer index
*/

int Document::getNumberOfLinesInBuffer(int bufferIndex) {
	int total = this->countCharactersWS(bufferIndex);
	int lines = static_cast<int>(ceil(static_cast<double>(total) / static_cast<double>(Pico::CONSOLE_WIDTH)));
	
	return lines;
}

void Document::add(char c, int line, int index) {
	stringstream sin;
	sin << c;

	string buffer = this->actionBuffer[this->actionBuffer.size() - 1];
	vector<data> textData = this->countCharacters(-1);
	int lineStart = textData[line].charStart;
	
	buffer.insert(lineStart + index, sin.str());
	this->actionBuffer.push_back(buffer);

	system("CLS");
	cout << this->display(-1, 1);
}

void Document::remove(int line, int index) {
	string buffer = this->actionBuffer[this->actionBuffer.size() - 1];
	vector<data> textData = this->countCharacters(-1);
	int lineStart = textData[line].charStart;
	
	buffer.erase(lineStart + index + 1, 1);
	this->actionBuffer.push_back(buffer);
	
	system("CLS");
	cout << this->display(-1, 1);

	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Document::undo() {
	int previous = this->actionBuffer.size() - 1;

	if (previous > 0){
		this->actionBuffer.pop_back();

		system("CLS");
		cout << this->display(previous, 1);
	} else {
		cout << "\a";
	}

	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/**
 * This function will return the text from a given buffer index value and
 * preform its output so that the text file will fit in the console. The
 * text from the most recent value in the buffer, if the value -1 is given.
 * If an integer greater than 0 is given, then the buffer at the given 
 * index is returned. If the given index is out of bounds, the most recent 
 * value in the buffer is returned.
 *
 * The second parameter will configure the start line so the contents of a 
 * longer text file can display on a small console screen. The text will
 * output starting at this line and go either to the end of the document, or
 * until there is no more room on the console screen, without having to
 * scroll down.
 * 
 * @access public
 * @param  int                               bufferIndex     The index of the buffer value to return
 * @param  int                               displayFromLine The line of text to start displaying at
 * @return string                            ret             The text in the supplied buffer index formatted for console viewing
 * @throws TextDisplayConfigurationException                 Occurs if displayFromLine is less than 1 or greater than the number of lines in the document
*/

string Document::display(int bufferIndex, int displayFromLine) {
	string ret = "";
	int maxLines = this->getNumberOfLinesInBuffer(bufferIndex);

//Fetch the data from the buffer
	if (bufferIndex > static_cast<int>(this->actionBuffer.size() - 1) || bufferIndex < 0) {
		ret = this->actionBuffer[this->actionBuffer.size() - 1];
	} else {
		ret = this->actionBuffer[bufferIndex];
	}

//Ensure the displayFromLine property is within range of the document
	if (displayFromLine < 1) {
		throw TextDisplayConfigurationException("The document can only begin display from line 1.");
	}
	
	if (displayFromLine > maxLines) {
		throw TextDisplayConfigurationException("This document is not long enough to display the number of requested lines.");
	}

//Trim the requested buffer to fit within the given constraints
//	vector<data> displayData = this->countCharacters(bufferIndex);
//	int to = 0;
//	int addNL = 0;

//Determine the extent of the document
//	if (maxLines < Pico::CONSOLE_HEIGHT) {
//		to = maxLines;
//	} else {
//	//Subtract Pico::APP_TOOLS_HEIGHT from the height to have room for application tools
//		to = (displayFromLine - 1) + Pico::DOCUMENT_HEIGHT - Pico::APP_TOOLS_HEIGHT;
//
//	//We can't display more lines than there are avaliable!
//		if (to > maxLines) {
//			to = maxLines;
//			addNL = (Pico::DOCUMENT_HEIGHT - Pico::APP_TOOLS_HEIGHT) - (displayData[to - 1].lineNumber - displayData[displayFromLine - 1].lineNumber);
//		}
//	}
//	
//Use the calculuated values above to pull the relavent data from the countCharacters() vector for trimming
//	int start = displayData[displayFromLine - 1].charStart;
//	int length = (displayData[to - 1].charEnd) - (displayData[displayFromLine - 1].charStart);
//	ret = ret.substr(start, length + 1);
//
//Add some \n to the return string so it takes the entire height of the doucment
//	for (int i = 0; i < addNL; i++) {
//		ret += "\n";
//	}

	return ret;
}