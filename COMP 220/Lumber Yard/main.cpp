/* 
  Author:  Oliver Spryn 
  Course:  COMP 220, Computer Programming II 
  Date:    12 November 2012 
  Description:  This file implements the driver 
                program for this assignment. 
*/ 

#include "FileOpenFailureException.h"
#include "Inventory.h"
#include <iostream>

int main() {
	try {
		Inventory il("inventory.txt");
	} catch (FileOpenFailureException e) {
		std::cout << e;
	}

	std::cout << std::endl << std::endl << "END" << std::endl;

	return 0;
}