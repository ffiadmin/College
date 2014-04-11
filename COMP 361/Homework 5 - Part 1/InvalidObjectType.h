/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The invalid cube object exception class. 
*/

#pragma once

#include "base.h"

class InvalidObjectType : public Base {
public : 
	InvalidObjectType(string message);
	~InvalidObjectType();
};