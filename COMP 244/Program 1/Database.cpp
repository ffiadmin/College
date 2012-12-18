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

#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sstream>
#include <string>
#include <vector>

#include "Database.h"
#include "DatabaseAttributeTypeUnknown.h"
#include "DatabaseConnectionException.h"
#include "DatabaseQueryFailedException.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

Database::Database(char localServerName[]) {
//Allocate the pre-connection handles
	this->sReturn = SQL_SUCCESS;
	this->sReturn = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &this->eHandle);
	this->sReturn = SQLSetEnvAttr(this->eHandle, SQL_ATTR_ODBC_VERSION, reinterpret_cast<void*>(SQL_OV_ODBC3), 4);
	SQLAllocHandle(SQL_HANDLE_DBC, this->eHandle, &this->cHandle);

//Connect to the database
	this->sReturn = SQLConnect(this->cHandle, reinterpret_cast<SQLCHAR*>(localServerName), SQL_NTS, NULL, 0, NULL, 0);

//Check to see if the connection was successful
	if (this->sReturn == SQL_SUCCESS || this->sReturn == SQL_SUCCESS_WITH_INFO) {
		//Success
	} else {
		throw DatabaseConnectionException(this->displayError(SQL_HANDLE_DBC, this->cHandle,
			"Connection to the database was unsuccessful. Double check the name of the local ODBC connection to the server."));
	}
}

Database::Database(char server[], char port[], char database[], char userID[], char password[]) {
//Allocate the pre-connection handles
	this->sReturn = SQL_SUCCESS;
	this->sReturn = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &this->eHandle);
	this->sReturn = SQLSetEnvAttr(this->eHandle, SQL_ATTR_ODBC_VERSION, reinterpret_cast<void*>(SQL_OV_ODBC3), 4);
	SQLAllocHandle(SQL_HANDLE_DBC, this->eHandle, &this->cHandle);

//Construct the C-String resembling the connection specifications
	char connectionString[512] = "DRIVER={SQL Server};SERVER=";
	strcat_s(connectionString, server);
	strcat_s(connectionString, ", ");
	strcat_s(connectionString, port);
	strcat_s(connectionString, ";DATABASE=");
	strcat_s(connectionString, database);
	strcat_s(connectionString, ";UID=");
	strcat_s(connectionString, userID);
	strcat_s(connectionString, ";PWD=");
	strcat_s(connectionString, password);
	strcat_s(connectionString, ";");

//Connect to the database
	SQLCHAR returnConection[1024];
	SQLCHAR* logon = reinterpret_cast<SQLCHAR*>(connectionString);
	this->sReturn = SQLDriverConnect(this->cHandle, NULL, logon, SQL_NTS, returnConection, 1024, NULL, SQL_DRIVER_NOPROMPT);

//Check to see if the connection was successful
	if (this->sReturn == SQL_SUCCESS || this->sReturn == SQL_SUCCESS_WITH_INFO) {
		//Success
	} else {
		throw DatabaseConnectionException(this->displayError(SQL_HANDLE_DBC, this->cHandle,
			"Connection to the database was unsuccessful. Double check the address and port of the server, name of the database, and logon credentials."));
	}
}

Database::~Database() {
	SQLDisconnect(this->cHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, this->cHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, this->eHandle);
}

string Database::displayError(unsigned int handleType, const SQLHANDLE &handle, string customMessage) {
//Fetch the error message from C++
	SQLCHAR SQLState[1024];
    SQLCHAR systemMessage[1024];

	SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, systemMessage, 1024, NULL);
	
//Construct a customized error message
	string message;
	message = "Message: ";
	message += reinterpret_cast<char*>(systemMessage);
	message += "\nSQL State: ";
	message += reinterpret_cast<char*>(SQLState);
	message += "\n\n";
	message += customMessage;

	return message;
}

void Database::query(char query[]) {
//Execute the query
	SQLINTEGER queryLength = static_cast<SQLINTEGER>(strlen(query));

	this->sReturn = SQLAllocHandle(SQL_HANDLE_STMT, this->cHandle, &this->sHandle);
	this->sReturn = SQLExecDirect(this->sHandle, reinterpret_cast<SQLCHAR*>(query),	queryLength);

//Ensure the query was executed successfully
	if (this->sReturn == SQL_SUCCESS || this->sReturn == SQL_SUCCESS_WITH_INFO) {
		//Success
	} else {
		throw DatabaseQueryFailedException(this->displayError(SQL_HANDLE_STMT, this->sHandle,
			"The supplied SQL query contained a syntax error."));
	}

	SQLLEN length;
	SQLCHAR Lname[21];
	SQLDOUBLE Salary;

	this->sReturn = SQLBindCol(this->sHandle, 1, SQL_C_CHAR, Lname, 21*sizeof(SQLCHAR), &length);
	this->sReturn = SQLBindCol(this->sHandle, 2, SQL_C_DOUBLE, &Salary, sizeof(SQLDOUBLE), &length);
	this->sReturn = SQLFetch(this->sHandle);

	
	while (this->sReturn == SQL_SUCCESS) {
		cout << "Lname: " << Lname << endl;
		cout << "Salary: $" << Salary << endl;
		this->sReturn = SQLFetch(this->sHandle);
	}

	SQLFreeHandle(SQL_HANDLE_STMT, this->sHandle);

	/*
//Count the number of returned attributes
	SQLSMALLINT columnCount;
	SQLNumResultCols(this->sHandle, &columnCount);

	SQLCHAR **colNames = new SQLCHAR*[columnCount];
	SQLSMALLINT *colTypes = new SQLSMALLINT[columnCount];
	SQLULEN *colSizes = new SQLULEN[columnCount];

//Walk over each colum in the returned object and determine its name, data type, and buffer length
	for (int i = 1; i <= columnCount; i++) {
		colNames[i - 1] = new SQLCHAR[100]; // -1 to conform to standard array notation

		SQLDescribeCol(this->sHandle, i, colNames[i - 1], 100, NULL, &colTypes[i - 1], &colSizes[i - 1], NULL, NULL);
	}

//Bind to each of the returned attributes
	SQLLEN length;
	//void* SQLData[100];
	void* data[100];
	
//Datatype references
//Dynamic SQL reading: http://www.anaesthetist.com/mnm/sql/odbc.htm
//ODBC numeric attribute type to C++ type maping: http://www.cplusplus.com/forum/general/36365/
//SQL type to C++ type: http://msdn.microsoft.com/en-us/library/windows/desktop/ms710150(v=vs.85).aspx
	for (int i = 0; i < columnCount; i++) {
		switch (colTypes[i]) {
			case 0 : //SQL_UNKNOWN_TYPE
				throw DatabaseAttributeTypeUnknown("The database returned an attribute of an unknown type.");
				break;

			case 1 : //SQL_CHAR
				SQLData[i] = new SQLCHAR[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_CHAR, SQLData, colSizes[i]*sizeof(SQLCHAR), &length);
				data.push_back(SQLData);
				break;

			case 12 : //SQL_VARCHAR
				SQLVARCHAR thing[100];
				this->sReturn = SQLBindCol(this->sHandle, 1, SQL_C_CHAR, &thing, colSizes[0]*sizeof(SQLVARCHAR), &length);
				data[0] = &thing;
				//data.push_back(SQLData);
				break;

			case 2 : //SQL_NUMERIC
				SQLData[i] = new SQLNUMERIC[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_NUMERIC, SQLData, colSizes[i]*sizeof(SQLNUMERIC), &length);
				data.push_back(SQLData);
				break;

			case 3 : //SQL_DECIMAL
				SQLData[i] = new SQLDECIMAL[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_DOUBLE, SQLData, colSizes[i]*sizeof(SQLDECIMAL), &length);
				data.push_back(SQLData);
				break;

			case 4 : //SQL_INTEGER 
				SQLData[i] = new SQLINTEGER[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_NUMERIC, SQLData, colSizes[i]*sizeof(SQLINTEGER), &length);
				data.push_back(SQLData);
				break;

			case 5 : //SQL_SMALLINT 
				SQLData[i] = new SQLSMALLINT[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_TINYINT, SQLData, colSizes[i]*sizeof(SQLSMALLINT), &length);
				data.push_back(SQLData);
				break;

			case 6 : //SQL_FLOAT
				SQLData[i] = new SQLFLOAT[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_FLOAT, SQLData, colSizes[i]*sizeof(SQLFLOAT), &length);
				data.push_back(SQLData);
				break;
			
			case 7 : //SQL_REAL
				SQLData[i] = new SQLREAL[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_DOUBLE, SQLData, colSizes[i]*sizeof(SQLREAL), &length);
				data.push_back(SQLData);
				break;

			case 8 : //SQL_DOUBLE
				SQLData[i] = new SQLDOUBLE[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_DOUBLE, SQLData, colSizes[i]*sizeof(SQLDOUBLE), &length);
				data.push_back(SQLData);
				break;

			case 9 : //SQL_DATETIME
			case 91 : //SQL_TYPE_DATE
				SQLData[i] = new SQLDATE[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_TIME, SQLData, colSizes[i]*sizeof(SQLDATE), &length);
				data.push_back(SQLData);
				break;

			case 92 : //SQL_TYPE_TIME
				SQLData[i] = new SQLTIME[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_TYPE_TIME, SQLData, colSizes[i]*sizeof(SQLTIME), &length);
				data.push_back(SQLData);
				break;

			case 93 : //SQL_TYPE_TIMESTAMP
				SQLData[i] = new SQLTIMESTAMP[colSizes[i]];
				this->sReturn = SQLBindCol(this->sHandle, i + 1, SQL_C_TIMESTAMP, SQLData, colSizes[i]*sizeof(SQLTIMESTAMP), &length);
				data.push_back(SQLData);
				break;

			default : //SQL_WACKO
				throw DatabaseAttributeTypeUnknown("The database returned an attribute of an unknown type.");
				break;
		}
		
	//Ensure this operation was executed successfully
		if (this->sReturn == SQL_SUCCESS || this->sReturn == SQL_SUCCESS_WITH_INFO) {
			//Success
		} else {
			stringstream error;
			error << "An error was encountered while building attribute name " << colNames[i] << ".";

			throw DatabaseQueryFailedException(this->displayError(SQL_HANDLE_STMT, this->sHandle, error.str()));
		}
	}
	
	this->sReturn = SQLFetch(this->sHandle);
	
//Ensure the fetching process was executed successfully
	if (this->sReturn == SQL_SUCCESS) {
		//Success
	} else {
		throw DatabaseQueryFailedException(this->displayError(SQL_HANDLE_STMT, this->sHandle,
			"The supplied SQL query contained a syntax error."));
	}
	
//Ensure this operation was executed successfully
	while (this->sReturn == SQL_SUCCESS) {
		cout << data[0] << endl;

		this->sReturn = SQLFetch(this->sHandle);
	}
*/
}