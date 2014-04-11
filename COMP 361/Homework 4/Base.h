/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The base exception class. 
*/

#pragma once

#include <exception>
#include <string>

using std::exception;
using std::string;

class Base : exception {
public : 
	Base(const string message);
	~Base();

	string getMessage() const;
	void setMessage(const string message);

private : 
	string message;
};