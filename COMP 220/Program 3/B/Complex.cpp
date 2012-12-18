/* 
  Author:  Oliver Spryn
  Course:  COMP 220, Computer Programming II 
  Date:    16 October 2012 
  Description:  This file contains the Comples class for all things
                related to complex numbers. Most common mathematical and 
				have been overloaded for use with these speical casess, and
				this class can cleanly output and read in a complex number. 
*/ 



#include "Complex.h"
#include <iostream>

Complex::Complex() {
	this->real = 0;
	this->imaginary = 0;
}

Complex::Complex(double real_part) {
	this->real = real_part;
	this->imaginary = 0;
}

Complex::Complex(double real, double imagainary) {
	this->real = real;
	this->imaginary = imagainary;
}

double Complex::getReal() {
	return this->real;
}

double Complex::getImaginary() {
	return this->imaginary;
}

ostream &operator<< (ostream &out, Complex c) {
	if (c.imaginary > 0) {
		out << c.real << " + " << c.imaginary << "i";
	} else {
		out << c.real << " - " << abs(c.imaginary) << "i";
	}

	return out;
}

istream &operator>> (istream &in, Complex &c) {
	double real = 0;
	char sign = '+';
	double imaginary = 0;

	in >> real;
	in.ignore();
	sign = in.get();
	in.ignore();
	in >> imaginary;
	in.ignore();

	if (sign == '+') {
		c.real = real;
		c.imaginary = imaginary;
	} else {
		c.real = real;
		c.imaginary = -imaginary;
	}
	
	return in;
}

bool Complex::operator== (Complex c) {
	if (this->real == c.real && this->imaginary == c.imaginary) {
		return true;
	} else {
		return false;
	}
}

Complex Complex::operator+ (Complex c) {
	double real = this->real + c.real;
	double imaginary = this->imaginary + c.imaginary;

	return Complex(real, imaginary);
}

Complex Complex::operator- (Complex c) {
	double real = this->real - c.real;
	double imaginary = this->imaginary - c.imaginary;

	return Complex(real, imaginary);
}

Complex Complex::operator* (Complex c) {
	double real = this->real * c.real - this->imaginary * c.imaginary;
	double imaginary = this->real * c.imaginary + this->imaginary * c.real;

	return Complex(real, imaginary);
}