/* 
  Author:  Oliver SPryn
  Course:  COMP 244, Database Management
  Date:    11 October 2012 
  Description:  This class is currently not being used. It may be used
                in the second version to introduce more specific abilities
				for queries on each SQL relation.
*/ 

#include "database.h"

class Employee : public Database {
public:
	Employee(char localServerName[]);
	Employee(char server[], char port[], char database[], char userID[], char password[]);
	void query(char query[]);
};