/* 
  Authors:  Dorian P. Yeager and Oliver Spryn
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This the driver program for the editor program. 
*/ 

#include "Document.h"
#include "Editor.h"
#include "FileBrowser.h"

int main(int argc, char *argv[]) {
//Let the user choose the desired file
	FileBrowser fb(".");
	string file = fb.print();

//Open the editor
	Document doc(file.c_str());
	Editor ed(&doc);
	ed.edit();
	
	return 0;
}