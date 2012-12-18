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

#include <iostream>

#include "Database.h"
#include "DatabaseConnectionException.h"
#include "DatabaseQueryFailedException.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
	char again = 'y';
	int SSN;

	do {
		cout << "Enter an employee's SSN for his or her last name and salary: ";
		cin >> SSN;

		if (cin.fail()) {
			cin.clear();
			cin.sync();
		}

		try {
			char cSSN[20];
			sprintf(cSSN, "%d", SSN);

			char SQL[256] = "SELECT Lname, Salary FROM COMPANY.dbo.Employee WHERE Ssn = '";
			strcat_s(SQL, cSSN);
			strcat_s(SQL, "';");
			
			Database db("SQLServer");
			db.query(SQL);
		} catch (DatabaseConnectionException e) {
			cout << e;
			//exit(1);
		} catch (DatabaseQueryFailedException e) {
			cout << e;
			//exit(1);
		}

		cout << endl << "Try another SSN? (y/n)";
		cin >> again;
		cout << endl;
	} while (again == 'y' || again == 'Y');

	return 0;
}