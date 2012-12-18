/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         11 September 2012 
 * Description:  This file contains the driver function for this 
 *               program. It will utilize the functions avaliable
 *               within the utils.cpp library for the bulk of the
 *               processing and user interaction, but will add some 
 *               minor formatting to the output of these functions 
 *               to visually tie the functionality of these
 *               functions together.
*/ 
#include <iostream>
#include "utils.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i ++) {
	//Output the contents of the supplied file
		echoFile(argv[i]);
		cout << endl << endl;

	//Either prompt the user to continue or end the program, depending on how many files
	//have been outputted to the console
		if (i < argc - 1) {
			halt(i, argc - 1);
		} else {
			end(i);
		}
	}

	return 0;
}