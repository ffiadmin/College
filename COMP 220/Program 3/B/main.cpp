/* 
  Author:  Dorian P. Yeager 
  Course:  COMP 220, Computer Programming II 
  Date:    16 October 2012 
  Description:  This file implements the driver 
                program for this assignment. 
*/ 

#include <cstdlib>

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;
using std::endl;

#include "Complex.h"

int main()
{
  cout << "The value of const Complex \"i\" is:  " << i << endl;
  cout << endl;

  Complex c0;
  cout << "c0 == " << c0 << endl;
  c0 = Complex(3.4);
  cout << "c0 == " << c0 << endl;
  c0 = Complex(4.5, 6.7);
  cout << "c0 == " << c0 << endl;
  cout << endl;

  Complex c1(1, -2);
  Complex c2(3, -4);

  cout << "c1 + c2 == " << c1 << " + " << c2 << " == " << c1 + c2 << endl;
  cout << "c1 - c2 == " << c1 << " - " << c2 << " == " << c1 - c2 << endl;
  cout << "c1 * c2 == " << c1 << " * " << c2 << " == " << c1 * c2 << endl;
  cout << endl;
  cout << "c1 == c2  --> ";
  if (c1 == c2)
    cout << "true";
  else
    cout << "false";
  cout << endl;
  cout << endl;

  ofstream fout;
  fout.open("inout.txt");
  if (fout.fail())
  {
    cout << "Failed to open \"inout.txt\" for output" << endl;
    exit(1);
  }

  cout << "Writing four complex numbers... ";
  fout << Complex(4, -10) << ' ' << c0 << ' ' << c1 << ' ' << c2 << ' ' << endl;
  fout.close();
  cout << "done" << endl;

  ifstream fin;
  fin.open("inout.txt");
  if (fin.fail())
  {
    cout << "Failed to open \"inout.txt\" for input" << endl;
    exit(1);
  }

  Complex cf;
  fin >> cf;
  if (cf == Complex(4, -10))
    cout << "Correctly read hard-coded value" << endl;
  else
    cout << "Failed to read hard-coded value" << endl;

  fin >> cf;
  if (cf == c0)
    cout << "Correctly read c0" << endl;
  else
    cout << "Failed to read c0" << endl;

  fin >> cf;
  if (cf == c1)
    cout << "Correctly read c1" << endl;
  else
    cout << "Failed to read c1" << endl;

  fin >> cf;
  if (cf == c2)
    cout << "Correctly read c2" << endl;
  else
    cout << "Failed to read c2" << endl;

  fin.close();

  return 0;
}