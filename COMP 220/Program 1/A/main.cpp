/*
  Author:       Oliver J. M. Spryn
  Course:       COMP 220, Computer Programming II
  Date:         5 September 2012
  Description:  This file encapsulates the complete functionality of this program.
                Between the main() driver function and two helper functions, this
				program will sum the values from 1 to 1/50,000,000 together from
				low to hight and hight to low by using both floats and doubles,
				then displays the various results from these calculations.
*/

#include <iostream>
using std::cout;
using std::endl;

float calculateF(int from, int to);
double calculateD(int from, int to);

int main(int argc, char *argv[]) {
//Where are our looping extrema???
	const int LOW = 1;
	const int HIGH = 50000000; // Fifty million

//Set the precision of the output
	cout.setf(std::ios::fixed);
	cout.setf(std::ios::showpoint);
	cout.precision(10);

//Display friendly, readable text to the user to convey meaningful information while processing the calculations
	cout << "This program will add 1 + 1/2 + 1/3 +  ... + 1/50,000,000 from low to high and high to "
		 << "low using floats then doubles for the calculations: "
	     << endl << endl;

	cout << "Adding from left to right using floats yields: " << calculateF(LOW, HIGH) << endl;
	cout << "Adding from right to left using floats yields: " << calculateF(HIGH, LOW) << endl << endl;
	cout << "Adding from left to right using doubles yields: " << calculateD(LOW, HIGH) << endl;
	cout << "Adding from right to left using doubles yields: " << calculateD(HIGH, LOW) << endl;

	return 0;
}

/**
 * This function will sum the values from 1 to 1/50,000,000 together by 
 * using floats for the calculation, either from low to high or high to
 * low, depending on which order the numbers are given in. For instance,
 * if the function is called like this:
 *
 *    calculateD(1, 100);
 *
 * then summing would occur like this: 1 + 1/2 + 1/3 + ... + 1/100. The
 * addition would take place in reverse if 100 were given as the first
 * argument. If from == to, then the function will display an error and
 * exit the program.
 *
 * Precondition  : two extrema must be provided to this function
 * Postcondition : the value from 1/from to 1/to will be caluculated in a
 *                 given order and returned
 *
 * @param     int      from          An extrema from which the calculation will start
 * @param     int      to            An extrema to which the calculation will end
 * @return    float    returnVal     The calculated value from 1/from to 1/to
*/

float calculateF(int from, int to) {
	float returnVal = 0.0;

//Add from 1.0 ... 1.0/50000000
	if (from < to) {
		for (int i = from; i <= to; i ++) {
			returnVal += 1.0 / i;
		}
//Add from 1.0/50000000 ... 1.0
	} else if (from > to) {
		for (int i = from; i >= to; i --) {
			returnVal += 1.0 / i;
		}
//Don't allow the same values, as it is probably an entry mistake
	} else {
		cout << "Wait... \"from\" and \"to\" are the same!" << endl;
		exit(1);
	}

	return returnVal;
}

/**
 * This function will sum the values from 1 to 1/50,000,000 together by 
 * using doubles for the calculation, either from low to high or high to
 * low, depending on which order the numbers are given in. For instance,
 * if the function is called like this:
 *
 *    calculateD(1, 100);
 *
 * then summing would occur like this: 1 + 1/2 + 1/3 + ... + 1/100. The
 * addition would take place in reverse if 100 were given as the first
 * argument. If from == to, then the function will display an error and
 * exit the program.
 *
 * Precondition  : two extrema must be provided to this function
 * Postcondition : the value from 1/from to 1/to will be caluculated in a
 *                 given order and returned
 *
 * @param     int      from          An extrema from which the calculation will start
 * @param     int      to            An extrema which to the calculation will end
 * @return    double   returnVal     The calculated value from 1/from to 1/to
*/

double calculateD(int from, int to) {
	double returnVal = 0.0;

//Add from 1.0 ... 1.0/50000000
	if (from < to) {
		for (int i = from; i <= to; i ++) {
			returnVal += 1.0 / i;
		}
//Add from 1.0/50000000 ... 1.0
	} else if (from > to) {
		for (int i = from; i >= to; i --) {
			returnVal += 1.0 / i;
		}
//Don't allow the same values, as it is probably an entry mistake
	} else {
		cout << "Wait... \"from\" and \"to\" are the same!" << endl;
		exit(1);
	}

	return returnVal;
}