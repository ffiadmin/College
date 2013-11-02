/**
 * Author      : Oliver Spryn
 * Course      : COMP 322, Advanced Programming 
 * Date        : 07 October 2013 
 * Description : This file implements the driver 
 *               program for this assignment. 
*/

#include <complex>
#include "MandelbrotSet.h"
#include "ThreadGroup.h"

using std::complex;
using std::cout;
using std::endl;

const int MATRIX_MAX = 10;
const int THREADS = 1;

int main() {
//Configuration
	double cx = -2.5, cy = -2.0;
	double dx = 0.005, dy = 0.005;
	int nx = 1000, ny = 800;

//Break up the configuration into data suitable for threads
	ThreadGroup tgroup;
	cDouble *corner;
	vector<MandelbrotSet*> vecMS(THREADS);

	int oldNy = ny;
	ny /= THREADS;

	for(int i = 0; i < THREADS; ++i) {
		corner = new cDouble(cx, cy + ny * dy * i);
		vecMS[i] = new MandelbrotSet(*corner, dx, dy, ny, nx);
		
		tgroup.add(MandelbrotSet::tfcn, (void*)vecMS[i]);
	}

	tgroup.execAndWait();
	delete corner;

	for(int i = 0; i < THREADS; ++i)
		delete vecMS[i];

//Output the results
	if (nx <= 10 && ny <= 10) {
		vvInt& counts = vecMS[0]->getCounts();
		int mVal = 0;

		for(int k = 0; k < THREADS; ++k) {
			counts = vecMS[k]->getCounts();

			for(int i = 0; i < ny; ++i) {
				for(int j = 0; j < nx; ++j) {
					mVal = counts[i][j];
				
						if (mVal >= 0 && mVal < 10) {
							cout << "    " << mVal;
						} else if (mVal >= 10 && mVal < 100) {
							cout << "   " << mVal;
						} else if (mVal >= 100 && mVal < 1000) {
							cout << "  " << mVal;
						} else {
							cout << " " << mVal;
						}
				}

				cout << endl;
			}
		}
	} else {
		float eTime = tgroup.getElapsedTime() / 1000.0;

		cout << "Test case 1: " << endl;
		cout << nx * oldNy << " counts computed in " << eTime << " seconds with ";
		cout << THREADS << " threads." << endl;
	}

	return 0;
}