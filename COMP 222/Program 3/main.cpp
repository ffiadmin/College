/*
  Author:  Mortimer Sneed <- kidding
  Author:  David B. Adams
  Course:  COMP 222, Data Structures
  Date:    17 April 2013
  Description:  This file implements the driver
                program for this assignment.
*/

#include <fstream>
using std::ifstream;
using std::ios;
using std::ofstream;

#include <iomanip>
using std::setw;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Customer.h"
#include "KeyedCollection.h"

int main()
{
  ifstream cdata("customers.txt");
  if (cdata.fail())
  {
    cout << "Failed to open \"customers.txt\" for reading" << endl;
    exit(1);
  }

  ifstream kdata("keys.txt");
  if (kdata.fail())
  {
    cout << "Failed to open \"keys.txt\" for reading" << endl;
    exit(1);
  }

  ofstream fout;
  string   ofname;
  Customer customer;

  /////////////////////////////////////////////////////////////////////////////
  // Binary search
  /////////////////////////////////////////////////////////////////////////////

  ofname = "bsearch.txt";
  fout.open(ofname.c_str());
  if (fout.fail())
  {
    cout << "Failed to open \"" << ofname << "\" for writing" << endl;
    exit(1);
  }

  cout << "Binary search" << endl;
  cout << "  Processing customers... ";

  KeyedCollection<int, Customer, true> kc1;
  while (cdata >> customer)
  {
    kc1.insert(customer.getKey(), customer);
    if (kc1.size() % 10 == 0)
    {
      int key;
      kdata >> key;
      kc1.find(customer, key);

      fout << setw(6) << kc1.size() << ' '
           << setw(6) << kc1.ncomp() << ' '
           << setw(6) << kc1.ncompTotal()
           << endl;
    }
  }

  fout.close();

  cout << "done!" << endl;
  cout << "  Data written to \"" << ofname << "\"" << endl;
  cout << endl;

  // Reset input data files
  cdata.clear();
  cdata.seekg(0, ios::beg);
  kdata.clear();
  kdata.seekg(0, ios::beg);

  /////////////////////////////////////////////////////////////////////////////
  // Sequential search
  /////////////////////////////////////////////////////////////////////////////

  ofname = "ssearch.txt";
  fout.open(ofname.c_str());
  if (fout.fail())
  {
    cout << "Failed to open \"" << ofname << "\" for writing" << endl;
    exit(1);
  }

  cout << "Sequential search" << endl;
  cout << "  Processing customers... ";

  KeyedCollection<int, Customer, false> kc2;
  while (cdata >> customer)
  {
    kc2.insert(customer.getKey(), customer);
    if (kc2.size() % 10 == 0)
    {
      int key;
      kdata >> key;
      kc2.find(customer, key);

      fout << setw(6) << kc2.size() << ' '
           << setw(6) << kc2.ncomp() << ' '
           << setw(6) << kc2.ncompTotal()
           << endl;
    }
  }

  fout.close();

  cout << "done!" << endl;
  cout << "Data written to \"" << ofname << "\"" << endl;
  cout << endl;

  return 0;
}