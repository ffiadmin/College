/*
  Author:  Oliver Spryn
  Course:  COMP 222, Data Structures
  Date:    Feb 19, 2013
  Description:  This file implements the driver
                program for this assignment.
*/

#include <fstream>
#include <iostream>
#include "Customer.h"
#include "KeyedCollection.h"
using namespace std;

int main()
{
  ifstream fin("customers.txt");
  if (fin.fail())
  {
    cout << "Failed to open \"customers.txt\" for reading" << endl;
    exit(1);
  }

  Customer customer;
  KeyedCollection<int, Customer> collection;
  while (fin >> customer)
    collection.insert(customer.getKey(), customer);

  cout << collection << endl;

  return 0;
}
