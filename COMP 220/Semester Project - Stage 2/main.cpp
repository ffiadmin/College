/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         12 October 2012 
 * Description:  This this is the driver file which is used to
 *               fetch the names of files to edit, load the files
 *    			 and display them in the editor.
*/ 

#include "Document.h"
#include "Pico.h"
#include <iostream>

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i ++) {
		Document d(argv[i]);
		Pico p(d);
	}

	std::cout << "All files have been edited\n";

	return 0;
}