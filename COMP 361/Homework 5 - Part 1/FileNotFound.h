/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The file not found exception class. 
*/

#pragma once

#include "Base.h"

class FileNotFound : public Base {
public : 
	FileNotFound(string message);
	~FileNotFound();
};