#include <Windows.h>
#include <sqlext.h>
#include <string>
/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This file is a wrapper for all of the functionality
                required to connect and query the SQL server. It provides
				multiple methods of connecting to a server via ODBC and
				will eventually be able to determine the number and types
				of each returned attribute.
*/ 

#include <vector>

using std::string;
using std::vector;

class Database {
public : 
	Database(char localServerName[]);
	Database(char server[], char port[], char database[], char userID[], char password[]);
	~Database();
	void query(char query[]);

protected : 
	HANDLE cHandle;
	string displayError(unsigned int handleType, const SQLHANDLE &handle, string customMessage);
	HANDLE eHandle;
	HANDLE sHandle;
	SQLRETURN sReturn;
};