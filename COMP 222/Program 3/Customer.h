/*
  Author:  Oliver Spryn
  Course:  COMP 222, Data Structures
  Date:    Feb 19, 2013
  Description:  This file contains the declaration for the Customer data container
                class.
*/

#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <string>
#include <fstream>
using namespace std;

class Customer
{
public:
  // Create a Customer object with the provided customer id,
  // zip code, sales volume, first name, middle name, and last
  // name (in that order)
  Customer(int,
           int,
           float,
           const string&,
           const string&,
           const string&);

  // Create an “empty” customer object
  Customer();

  // Accessors
  int    getKey()        const;
  int    getZip()        const;
  float  getSales()      const;
  string getFirstName()  const;
  string getMiddleName() const;
  string getLastName()   const;

  // Input Customer record
  friend istream& operator>>(istream&,
                             Customer&);

  // Output Customer’s last name
  friend ostream& operator<<(ostream&,
                             const Customer&);

private:
  int key;
  int zip;
  float sales;
  string firstName;
  string middleName;
  string lastName;
};

#endif