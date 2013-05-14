/*
Author:  Oliver Spryn
Course: COMP 222, Data Structures
Date: 7 March 2012
Description: This file implements the driver
program for this assignment.
*/

#include "Stack.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

typedef Stack<string, 200> StackURL;
const string IN = "in3.txt";
const string OUT = "out3_ab.txt";
const string START = "http://www.acm.org/";

int main()
{
  StackURL fwd;
  StackURL bak;
  string cmd, URL, temp;

//Open the command file input stream
  ifstream fin;
  fin.open(IN);

  if (fin.fail()) {
	  cout << "Could not open file " << IN << endl;
	  exit(1);
  }

//Open (or create) the output log
  ofstream fout;
  fout.open(OUT);

//Push the inital page on the back stack
  temp = START;

  while(!fin.eof()) {
	  fin >> cmd;

	  if (cmd == "VISIT") {
		fin >> URL;
		bak.push(temp);
		temp = URL;
		fout << URL << endl;
	  } else if (cmd == "BACK") {
		  if (!bak.empty()) {
			  fwd.push(temp);
			  temp = bak.pop();
			  fout << temp << endl;
		  } else {
			  fout << "Ignored" << endl;
		  }
	  } else if (cmd == "FORWARD") {
		   bak.push(temp);

		  if (!fwd.empty()) {
			  temp = fwd.pop();
			  fout << temp << endl;
		  } else {
			  fout << "Ignored" << endl;
		  }
	  } else {
		  break;
	  }
  }
	  
//Close the open streams
	fin.close();
	fout.close();

  return 0;
}