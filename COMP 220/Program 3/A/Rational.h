/* 
  Author:  Oliver Spryn
  Course:  COMP 220, Computer Programming II 
  Date:    16 October 2012 
  Description:  This file contains the Rational class for all things
                related to fractions. Most common mathematical and 
				comparison operators have been overloaded, and this
				class can cleanly output and read in a rational number. 
*/ 



#include <istream>
#include <ostream>

using std::istream;
using std::ostream;

class Rational {
	friend ostream &operator<< (ostream &out, Rational r);
	friend istream &operator>> (istream &out, Rational &r);

public : 
	Rational();
	Rational(int numerator);
	Rational(int numerator, int denominator);

	int getDenominator();
	int getNumerator();
	double getRational();

	bool operator== (Rational r);
	bool operator< (Rational r);
	bool operator<= (Rational r);
	bool operator> (Rational r);
	bool operator>= (Rational r);
	Rational operator+ (Rational r);
	Rational operator- (Rational r);
	Rational operator* (Rational r);
	Rational operator/ (Rational r);

private : 
	int denominator;
	int numerator;
	int GCD(int first, int second);
	void normalize();
	int prepare(Rational r);
};