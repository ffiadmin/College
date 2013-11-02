/**
 * Author      : Dorian P. Yeager & Oliver Spryn
 * Course      : COMP 322, Advanced Programming 
 * Date        : 17 August 2013
 * Description : This file implements the driver program for this assignment. 
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include "ThreadGroup.h"

using std::cout;
using std::endl;
using std::fixed;
using std::ofstream;
using std::setprecision;

const unsigned int NITERS = 20000;

double bigDubPower(int divisor = 1) {
	const int CONSTANT_MULTIPLE = 30000;
	double result = 1.0;

	for (int i = 0; i < NITERS / divisor; ++i)
		for (int i = 0; i < CONSTANT_MULTIPLE; ++i)
			result *= 1.00000001;

	return result;
}

unsigned __stdcall busy_work(void *p) {
	return (unsigned) bigDubPower((int) p);
}

void test() {
	ThreadGroup tgroup;
	ofstream fout;
	fout.open("out.txt");

	for (int i = 1; i <= 16; ++i) {
		if (20000 % i == 0) {
			tgroup.add(busy_work, (void*) i);
			tgroup.execAndWait();

			cout << endl;
			cout << tgroup.getElapsedTime() << " milliseconds" << endl;
			fout << i << " " << tgroup.getElapsedTime() << endl;
			tgroup.clear();
		}
	}

	fout.close();
}

int main() {
	test();

	return 0;
}