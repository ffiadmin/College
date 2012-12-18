/* 
  Authors:  Dorian P. Yeager
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class contains the documement and applies direct changes to its content. 
*/ 

#ifndef __DOCUMENT_H
#define __DOCUMENT_H

#include <string>
#include <stack>
using std::string;
using std::stack;
#include "Change.h"
#include "Context.h"

class Document {
	Context currentContext, savedContext;
	string text;
	const char *fileName;
	stack<Change*> history;
public:
	Document(const char *fileName);
	void save(const char *fileName);
	void apply(Change &c);
	void moveUp(int lines = 1);
	void moveDown(int lines = 1);
	void insert(char ch);
						 // Inserts ch before the current character.
	char remove();       // Removes the current character.
	int currentLineOffset();
		                 // Returns the offset of the current context within
	                     // the current line.
	void undo();
	char &operator *();  // Returns a reference to the current character.
	void operator ++();  // Moves forward one character.
	void operator --();  // Moves back one character.
	bool atEnd() { return currentContext == end(); }
	bool atBeginning() { return currentContext == begin(); }
	bool inSameLine(Context c1, Context c2);
	void goTo(Context context);
	Context begin();	  // Returns the context of the beginning of
		                  // the file.
	Context end();	      // Returns the context of the end of the file.
	Context lineBegin();  // Returns the context of the beginning of
		                  // the current line.
	Context lineEnd();	  // Returns the context of the end of the
		                  // current line.
	Context getContext(); // Returns the current context.
};

#endif
