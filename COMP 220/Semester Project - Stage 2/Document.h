/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         15 October 2012 
 * Description:  This class loads the text file and adds
                 all of the interactivity to the content,
				 such as entry and deletion of text, undos,
				 and saves.
*/ 


#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

typedef struct {
public : 
	int lineNumber;
	int charStart;
	int charEnd;
} data;

class Document {
public : 
	Document(string d);

	string getDocumentName();
	
	void add(char c, int line, int index);
	string display(int bufferIndex, int displayFromLine);
	void enableEditing();
	void remove(int line, int index);
	void undo();

private : 
	vector<string> actionBuffer;
	string documentName;

	vector<data> countCharacters(int bufferIndex);
	int countCharactersWS(int bufferIndex);
	int getNumberOfLinesInBuffer(int bufferIndex);
	void openFile();
	void save();
	void saveAs();
};

#endif