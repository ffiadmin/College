/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This class is currently not being used. It may be used
                in the second version to introduce more specific abilities
				for queries on each SQL relation.
*/ 

#include "Employee.h"
#include <iostream>

Employee::Employee(char localServerName[]) : Database(localServerName) {
	//The super constructor will handle this ;)
}

Employee::Employee(char server[], char port[], char database[], char userID[], char password[]) : 
	Database(server, port, database, userID, password) {
	//The super constructor will handle this ;)
}

void Employee::query(char query[]) {
	SQLRETURN    rc;
SQLSMALLINT  sNumParams;


rc = SQLPrepare(this->sHandle, (SQLCHAR *) query, SQL_NTS);
if (SQL_SUCCEEDED(rc)) {
rc = SQLNumParams(this->sHandle, &sNumParams);
if (SQL_SUCCEEDED(rc))
fprintf(stdout, "Number of parameters: %hd\n",
sNumParams);
}


//	Database::query(query);
	/*SQLVARCHAR Fname[15];
	SQLCHAR Minit[1];
	SQLVARCHAR Lname[15];
	SQLCHAR Ssn[9];
	SQL_TIMESTAMP_STRUCT Bdate;
	SQLVARCHAR Address[35];
	SQLCHAR Sex[1];
	SQLDECIMAL Salary(10, 2);
	SQLCHAR Super_ssn[9];
	SQLINTEGER Dno;

	SQLLEN length;
	Database::query(query);

	this->sReturn = SQLBindCol(this->sHandle, 1, SQL_C_CHAR, Fname, 15*sizeof(SQLVARCHAR), &length);
	this->sReturn = SQLBindCol(this->sHandle, 2, SQL_C_CHAR, Minit, 1*sizeof(SQLCHAR), &length);
	this->sReturn = SQLBindCol(this->sHandle, 3, SQL_C_CHAR, Lname, 15*sizeof(SQLVARCHAR), &length);
	this->sReturn = SQLBindCol(this->sHandle, 4, SQL_C_CHAR, Ssn, 9*sizeof(SQLCHAR), &length);
	this->sReturn = SQLBindCol(this->sHandle, 5, SQL_C_TYPE_TIMESTAMP, Bdate, sizeof(SQL_TIMESTAMP_STRUCT), &length);*/
}