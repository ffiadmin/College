/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: Lorem ipsum. Do you read this?
*/

#include "Base.h"

Base::Base(string message) : message(message) { }
Base::~Base() { }

string Base::getMessage() const {
	return message;
}

void Base::setMessage(const string message) {
	if (message != "") {
		this->message = message;
	}
}