/* 
  Author:  Oliver Spryn 
  Course:  COMP 220, Computer Programming II 
  Date:    Nov 30 2012 
  Description:  This is the configuration file for certain program parameters. 
*/

#ifndef CONFIG_H
#define CONFIG_H

class Config {
public:
	static const int ANTS_INIT = 100;
	static const int COLUMNS = 20;
	static const int DOODLEBUG_INIT = 5;
	static const int DOODLEBUG_STRAVE_MOVES = 3;
	static const int ROWS = 20;

	static const int ORGANISM = 0;
	static const int ANT = 1;
	static const int DOOBLEBUG = 2;

	static const char ORGANISM_CHAR = 'O';
	static const char ANT_CHAR = 'A';
	static const char DOOBLEBUG_CHAR = 'D';
};

#endif