/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The base exception class for invalid object types from a config file. 
*/

#include "InvalidObjectType.h"

InvalidObjectType::InvalidObjectType(string message) : Base(message) { }
InvalidObjectType::~InvalidObjectType() { }