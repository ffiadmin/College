/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This class constructs the queries and interacts with the 
                user for each of the major portions of this program's
				functionality.
*/

#include "Database.h"
#include "DatabaseAttributeTypeUnknown.h"
#include "DatabaseConnectionException.h"
#include "DatabaseQueryFailedException.h"

class Employee : public Database {
public : 
	Employee(char localServerName[]);
	
	bool getSupervisees();
	void getTopSalaries();
	void getTopHours();

private : 
	vector<vector<string>> queryData;
};