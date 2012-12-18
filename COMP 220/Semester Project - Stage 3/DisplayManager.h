/* 
  Authors:  Dorian P. Yeager
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class contains instructions to display file content the console. 
*/ 


#ifndef __DISPLAYMANAGER_H
#define __DISPLAYMANAGER_H

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include "Document.h"

class DisplayManager {
	enum {DEF_RADIUS = 10};
public:
	DisplayManager(Document &doc, int radius = DEF_RADIUS) 
		:doc(doc), radius(radius) {}
	void displayCurrentLine(ostream &out);
	void displayNeighborhood(ostream &out=cout);
private:
	Document &doc;
	int radius;
};

#endif
