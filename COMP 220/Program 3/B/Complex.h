/* 
  Author:  Oliver Spryn
  Course:  COMP 220, Computer Programming II 
  Date:    16 October 2012 
  Description:  This file contains the Comples class for all things
                related to complex numbers. Most common mathematical and 
				have been overloaded for use with these speical casess, and
				this class can cleanly output and read in a complex number. 
*/ 



#include <istream>
#include <ostream>

using std::istream;
using std::ostream;

class Complex {
	friend ostream &operator<< (ostream &out, Complex c);
	friend istream &operator>> (istream &out, Complex &c);

public:
	Complex();
	Complex(double real_part);
	Complex(double real, double imaginary);

	double getReal(); //I mean, get real in a nice way ;)
	double getImaginary();

	bool operator== (Complex r);
	Complex operator+ (Complex r);
	Complex operator- (Complex r);
	Complex operator* (Complex r);
	Complex operator/ (Complex r);

private : 
	double imaginary;
	double real;
};

const Complex i(0, 1);