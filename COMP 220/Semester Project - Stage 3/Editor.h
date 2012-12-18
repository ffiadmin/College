/* 
  Authors:  Dorian P. Yeager
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class contains the editor and is used to provide interaction between the user and document. 
*/ 

#ifndef __EDITOR_H
#define __EDITOR_H

#include "Document.h"
#include "DisplayManager.h"
#include <iostream>
using std::istream;
using std::getline;

enum {DEF_BASEX = 0, DEF_BASEY = 23};

class Editor {
public:
	Editor(Document *doc);
	~Editor();
	Change *getChange(istream &in);
	void edit();
private:
	Document *doc;
	DisplayManager *dispMan;
	string buffer;
	Change *carveInsert();
	int baseX, baseY;

	int changes;
};

#endif
