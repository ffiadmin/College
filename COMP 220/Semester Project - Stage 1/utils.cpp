/**
 * Author:       Oliver J. Spryn
 * Course:       COMP 220, Computer Programming II 
 * Date:         11 September 2012 
 * Description:  This file contains most of the logic for this stage
 *               of the program. At this point, it will request the
 *               necessary input from the user as required by the 
 *               drive program, and will also open and display the 
 *               contents of a text file to the console.
*/ 
#include <iostream>
#include <fstream>
#include "utils.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;

/**
 * This function will halt the processing and visual output of this 
 * program until the user has pressed "Enter" or "Return" to continue
 * the execution of the program.
 *
 * Precondition  : the program must have completed displaying a text 
 *                 file to the console
 * Postcondition : the program will halt until further input by the 
 *                 user
 *
 * @param     int      viewing       The number of the file that the user has finished viewing
 * @return    int      total         The total number of files the program will print to the screen
*/

void halt(int viewing, int total) {
//Prompt the user to press "Enter" or "Return"
	cout << "You have viewed " << viewing << " out of " << total << " text files. "
		 << "Press \"Enter\" or \"Return\" to continue to the next file."
		 << endl << endl;

	cin.get();
	cin.sync();
}

/**
 * This function will open a file text file and display its entrire contents 
 * to the screen. Although, the output will be slightly enhanced, and will
 * display as follows:
 *
 *     ------------- Begin <name_of_file>...
 *
 *     <contents_of_text_file>
 *
 *     ------------- End <name_of_file>...
 *
 *
 * Precondition  : the supplied path to the function must link to a valid
 *                 text file
 * Postcondition : the program will display the contents of the file
 *                 to the user
 *
 * @param     string   file          A valid, relative path to the text file
*/

void echoFile(string file) {
	char next;
	
//Open the file and check to see if opening succeeded
	fstream fin;
	fin.open(file);
	
	if (fin.fail()) {
		cout << "Yikes! We couldn't open " << file << " are you sure it exists?"
			 << endl;
		
		exit(1);
//Print a header before the file output
	} else {
		cout << "------------- Begin " << file << "..."
			 << endl << endl;
	}

//Write out the file to the console
	while (fin.get(next) && !fin.eof()) {
		cout << next;
	}

//Print the footer after the file output
	cout << endl << endl
		 << "------------- End " << file << "...";

	fin.close();
}

/**
 * This function will halt the automatic ending of this program until
 * the user has pressed any key to deliberately end the program.
 *
 * Precondition  : the program must have finished displaying the last
 *                 file to the console
 * Postcondition : the program will halt until further input by the 
 *                 user
 *
 * @return    int      total         The total number of files the program has printed to the screen
*/

void end(int total) {
	cout << "You have viewed " << total << " out of " << total << " text files. "
		 << "Press \"Enter\" or \"Return\" to exit the program."
		 << endl << endl;

	cin.get();
	cin.sync();
}