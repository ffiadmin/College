/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This class constructs the queries and interacts with the 
                user for each of the major portions of this program's
				functionality.
*/

#include <iostream>
#include "Employee.h"

using std::cout;
using std::cin;
using std::endl;

Employee::Employee(char localServerName[]) : Database(localServerName) { }

bool Employee::getSupervisees() {
//Prompt the user for an employee's last name
	string lName;
	string SSN;

	cout << "Enter last name of employee: ";
	cin >> lName;

//Perform the first query on the database, by last name
	try {			
		queryData = this->query("SELECT * FROM COMPANY.dbo.Employee WHERE Lname = '" + lName + "'");
	} catch (DatabaseAttributeTypeUnknown e) {
		cout << e;
	} catch (DatabaseQueryFailedException e) {
		cout << e;
	}

//How man employees with the entered last name retrieved?
	int size = queryData.size();
			
	if (size > 1) {
	//Output the results
		for (int i = 0; i < size; i++) {
			cout << queryData[i][2] << ", " << queryData[i][0] << " " << queryData[i][3] << endl;
		}

		cout << endl << "Select ssn from list: ";
		cin >> SSN;
	} else if (size == 1) {
		SSN = queryData[0][3];
	} else {
		cout << "Sorry, there aren't any employees with the last name of \"" << lName << "\"."
			 << endl;

		return false;
	}

//Perform the second query on the database, by SSN
	try {
		queryData = this->query("SELECT * FROM COMPANY.dbo.Employee WHERE Super_ssn = '" + SSN + "'");
	} catch (DatabaseAttributeTypeUnknown e) {
		cout << e;
	} catch (DatabaseQueryFailedException e) {
		cout << e;
	}

//Output the results
	if (size >= 1) {
		for (int i = 0; i < queryData.size(); i++) {
			cout << queryData[i][2] << ", " << queryData[i][0] << " " << queryData[i][3] << endl;
		}
	} else {
		cout << "Sorry, there aren't any supervisees with a supervisor with the last name of \"" << lName << "\"."
			 << endl;
				
		return false;
	}

	return true;
}

void Employee::getTopSalaries() {
//Perform the query on the database
	try {			
		queryData = this->query("SELECT TOP 5 * FROM COMPANY.dbo.Employee ORDER BY Salary DESC");
	} catch (DatabaseAttributeTypeUnknown e) {
		cout << e;
	} catch (DatabaseQueryFailedException e) {
		cout << e;
	}

//Output the results
	for (int i = 0; i < queryData.size(); i++) {
		cout << queryData[i][2] << ", " << queryData[i][0] << " (" << queryData[i][3]
				<< ") has a salary of $" << queryData[i][7] << endl;
	}
}

void Employee::getTopHours() {
//Perform the query on the database
	try {			
		queryData = this->query("SELECT TOP 5 * FROM COMPANY.dbo.WORKS_ON RIGHT JOIN COMPANY.dbo.EMPLOYEE ON COMPANY.dbo.WORKS_ON.Essn = COMPANY.dbo.EMPLOYEE.Ssn ORDER BY Hours DESC");
	} catch (DatabaseAttributeTypeUnknown e) {
		cout << e;
	} catch (DatabaseQueryFailedException e) {
		cout << e;
	}

//Output the results
	for (int i = 0; i < queryData.size(); i++) {
		cout << queryData[i][5] << ", " << queryData[i][3] << " (" << queryData[i][0]
				<< ") has worked a total of " << queryData[i][2] << " hours" << endl;
	}
}