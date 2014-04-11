/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The base exception class for files not located on the file system. 
*/

#include "FileNotFound.h"

FileNotFound::FileNotFound(string message) : Base(message) { }
FileNotFound::~FileNotFound() { }