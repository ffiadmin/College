/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This file is the driver program which
                will gather input from the user and 
				trigger a query on the database to 
				display the information the user has
				requested.
*/ 
#include <conio.h>
#include <iostream>
#include "Employee.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
	char again;

//Connect to the local database server
	Employee db("SQLServer");

	do {
		system("CLS");

	//Prompt the user for program options
		char option;
		cout << "          QUERY OPTIONS" << endl
			 << "(a) Find supervisees at all levels." << endl
			 << "(b) Find highest paid workers." << endl
			 << "(c) Find the most worked workers." << endl
			 << "(q) Quit." << endl << endl
			 << "Type in your option: ";

		cin >> option;
		cout << endl;

	//Switch between the differnt program options
		switch (toupper(option)) {
			case 'A' : {
				db.getSupervisees();
				break;
			}

			case 'B' : {
				db.getTopSalaries();
				break;
			}

			case 'C' : {
				db.getTopHours();
				break;
			}

			default : 
				exit(0);
				break;
		}

	//Ask the user if the program should run again
		cout << endl << "Try another option? (y/n) ";
		again = getche();
		cout << endl << endl;
	} while (toupper(again) == 'Y');

	return 0;
}