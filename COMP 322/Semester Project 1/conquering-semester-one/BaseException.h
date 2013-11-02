/**
 * Base Exception class
 *
 * This class is designed to manage all of the common operations
 * which may take place on an exception. It's constructor will
 * accept a string as the argument for the error message or
 * code. This object can be printed the console in a clear
 * well, formatted style like so:
 *
 * ...
 * } catch(BaseException e) {
 *     cout << e;
 * }
 * ...
 *
 * @abstract
 * @author    Oliver Spryn
 * @namespace global
 * @package   exceptions
*/

#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>
#include <ostream>

using std::exception;
using std::ostream;
using std::string;

class BaseException : public exception {
        friend ostream &operator<< (ostream &out, BaseException be);

public : 
        BaseException(string error);

private : 
        string error;
};

#endif