/*
  Author:  Oliver Spryn
  Course:  COMP 222, Data Structures
  Date:    Feb 19, 2013
  Description:  This file contains the definition for the Customer data container
                class. This class contains several accessor functions to get info-
				rmation about the stored data, as well as overloaded construction
				and insertion/extraction operators to get and set customer data.
*/


#include "Customer.h"

Customer::Customer(int key, int zip, float sales, const string& first, const string& middle, const string& last) {
	this->key = key;
	this->zip = zip;
	this->sales = sales;
	this->firstName = first;
	this->middleName = middle;
	this->lastName = last;
}

Customer::Customer() {
	this->key = 0;
	this->zip = 10000;
	this->sales = 0.0;
	this->firstName = "John";
	this->middleName = "Jacob Jingleheimer";
	this->lastName = "Schmidt";
}

int Customer::getKey()const {
	return this->key;
}

int Customer::getZip() const {
	return this->zip;
}

float Customer::getSales() const {
	return this->sales;
}

string Customer::getFirstName() const {
	return this->firstName;
}

string Customer::getMiddleName() const {
	return this->middleName;
}

string Customer::getLastName() const {
	return this->lastName;
}

istream& operator>>(istream& in, Customer& c) {
	in >> c.key >> c.zip >> c.sales >> c.firstName >> c.middleName >> c.lastName;
	return in;
}

ostream& operator<<(ostream& out,  const Customer& c) {
	out << c.lastName;
	return out;
}