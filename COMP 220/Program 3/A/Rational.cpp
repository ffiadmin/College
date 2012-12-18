/* 
  Author:  Oliver Spryn
  Course:  COMP 220, Computer Programming II 
  Date:    16 October 2012 
  Description:  This file contains the Rational class for all things
                related to fractions. Most common mathematical and 
				comparison operators have been overloaded, and this
				class can cleanly output and read in a rational number. 
*/ 


#include "Rational.h"
#include "InitException.h"

#include <iostream>

Rational::Rational() {
	this->numerator = 0;
	this->denominator = 1;
}

Rational::Rational(int numerator) {
	this->numerator = numerator;
	this->denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
	if (denominator == 0) {
		throw InitException("You cannot divide by 0");
	}

	this->numerator = numerator;
	this->denominator = denominator;
	this->normalize();
}

ostream &operator<< (ostream &out, Rational r) {
	if (r.denominator == 1) {
		out << r.numerator;
	} else {
		out << r.numerator << "/" << r.denominator;
	}

	return out;
}

istream &operator>> (istream &in, Rational &r) {
	int numerator = 0;
	int denominator = 0;

	in >> numerator;
	in.ignore();
	in >> denominator;

	r.numerator = numerator;
	r.denominator = denominator;

	return in;
}


int Rational::getDenominator() {
	return this->denominator;
}

int Rational::getNumerator() {
	return this->numerator;
}

double Rational::getRational() {
	return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
}

bool Rational::operator== (Rational r) {
	if (this->numerator * r.denominator == this->denominator * r.numerator) {
		return true;
	} else {
		return false;
	}
}

bool Rational::operator< (Rational r) {
	if (this->getRational() < r.getRational()) {
		return true;
	} else {
		return false;
	}
}

bool Rational::operator<= (Rational r) {
	if (this->operator< (r) || this->operator== (r)) {
		return true;
	} else {
		return false;
	}
}

bool Rational::operator> (Rational r) {
	return !this->operator<=(r);
}

bool Rational::operator>= (Rational r) {
	return !this->operator<(r);
}

Rational Rational::operator+ (Rational r) {
	int numerator = (r.denominator * this->numerator) + (this->denominator * r.numerator);
	int denominator = this->denominator * r.denominator;

	return Rational(numerator, denominator);
}

Rational Rational::operator- (Rational r) {
	int numerator = (r.denominator * this->numerator) - (this->denominator * r.numerator);
	int denominator = this->denominator * r.denominator;

	return Rational(numerator, denominator);
}

Rational Rational::operator* (Rational r) {
	int numerator = this->numerator * r.numerator;
	int denominator = this->denominator * r.denominator;

	return Rational(numerator, denominator);
}

Rational Rational::operator/ (Rational r) {
	int numerator = this->numerator * r.denominator;
	int denominator = this->denominator * r.numerator;

	return Rational(numerator, denominator);
}

void Rational::normalize() {
//Check to see if the denominator or numerator is negative
	bool dNegative = false;
	bool nNegative = false;

	if (this->denominator < 0) {
		dNegative = true;
	}

	if (this->numerator < 0) {
		nNegative = true;
	}

//Bring the negative sign up to the top, or cancel the signs if they are on top and bottom
	if ((dNegative && !nNegative) || (dNegative && nNegative)) {
		this->denominator *= -1;
		this->numerator *= -1;
	}

//Perform the Euclidean Algorithm to find the GCD (thank you Discrete Math)
	int GCD = this->GCD(this->numerator, this->denominator);
	this->numerator /= GCD;
	this->denominator /= GCD;
}

int Rational::GCD(int first, int second) {
	int tempFirst = 0;

	while (second > 0) {
		tempFirst = first;

		if (first < second) {
			//first = first :D
			second = second % tempFirst;
		} else {
			first = second;
			second = tempFirst % second;
		}
	}

	return abs(first); //GCDs should never be negative, in this case
}

int Rational::prepare(Rational r) {
	int rNumerator = r.numerator * this->denominator;

	this->numerator *= r.denominator;
	this->denominator *= r.numerator;

	return rNumerator;
}