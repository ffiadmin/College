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

#include "Rational.h"
#include "InitException.h"

int main()
{
try {
  Rational r0;
  cout << "r0 == " << r0 << endl;
  r0 = Rational(3);
  cout << "r0 == " << r0 << endl;
  r0 = Rational(1, 2);
  cout << "r0 == " << r0 << endl;
  r0 = Rational(-1, 2);
  cout << "r0 == " << r0 << endl;
  r0 = Rational(1, -2);
  cout << "r0 == " << r0 << endl;
  r0 = Rational(-1, -2);
  cout << "r0 == " << r0 << endl;
  r0 = Rational(4, 8);
  cout << "r0 == " << r0 << endl;
  r0 = Rational(-4, 8);
  cout << "r0 == " << r0 << endl;
  r0 = Rational(4, -8);
  cout << "r0 == " << r0 << endl;
  r0 = Rational(-4, -8);
  cout << "r0 == " << r0 << endl;
  cout << endl;

  Rational r1(1, 2);
  Rational r2(3, 4);
 
  cout << "r1 + r2 == " << r1 << " + " << r2 << " == " << r1 + r2 << endl;
  cout << "r1 - r2 == " << r1 << " - " << r2 << " == " << r1 - r2 << endl;
  cout << "r1 * r2 == " << r1 << " * " << r2 << " == " << r1 * r2 << endl;
  cout << "r1 / r2 == " << r1 << " / " << r2 << " == " << r1 / r2 << endl;
  cout << endl;

  cout << "r1 == r2  --> ";
  if (r1 == r2)
    cout << "true";
  else
    cout << "false";
  cout << endl;

  cout << "r1 <= r2  --> ";
  if (r1 <= r2)
    cout << "true";
  else
    cout << "false";
  cout << endl;

  cout << "r1 >= r2  --> ";
  if (r1 >= r2)
    cout << "true";
  else
    cout << "false";
  cout << endl;

  cout << "r1 < r2   --> ";
  if (r1 < r2)
    cout << "true";
  else
    cout << "false";
  cout << endl;

  cout << "r1 > r2   --> ";
  if (r1 > r2)
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

  cout << "Writing four rational numbers... ";
  fout << Rational(4, -8) << ' ' << r0 << ' ' << r1 << ' ' << r2 << ' ' << endl;
  fout.close();
  cout << "done" << endl;

  ifstream fin;
  fin.open("inout.txt");
  if (fin.fail())
  {
    cout << "Failed to open \"inout.txt\" for input" << endl;
    exit(1);
  }

  Rational rf;
  fin >> rf;
  if (rf == Rational(-1, 2))
    cout << "Correctly read hard-coded value" << endl;
  else
    cout << "Failed to read hard-coded value" << endl;

  fin >> rf;
  if (rf == r0)
    cout << "Correctly read r0" << endl;
  else
    cout << "Failed to read r0" << endl;

  fin >> rf;
  if (rf == r1)
    cout << "Correctly read r1" << endl;
  else
    cout << "Failed to read r1" << endl;

  fin >> rf;
  if (rf == r2)
    cout << "Correctly read r2" << endl;
  else
    cout << "Failed to read r2" << endl;

  fin.close();
} catch (InitException e) {
  cout << e;
}

  return 0;
}