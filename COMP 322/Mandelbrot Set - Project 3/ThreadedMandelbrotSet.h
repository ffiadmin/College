/**
 * Author      : Oliver Spryn
 * Course      : COMP 322, Advanced Programming 
 * Date        : 31 October 2013 
 * Description : This file declares the class which will later
 *               execute and store the results of executing
 *               the Threaded Mandelbrot algorithm.
*/

#include <complex>
#include <iostream>
#include <string>
#include <vector>

#include "Color.h";
#include "MandelbrotSet.h"
#include "Image.h"
#include "ThreadGroup.h"

using std::complex;
using std::ostream;
using std::string;
using std::vector;

typedef complex<double> Complex;
typedef vector<vector<int>> vvInt;

class ThreadedMandelbrotSet { 
public : 
	ThreadedMandelbrotSet(const Complex& zCorner, 
		double dx, double dy, int nx, int ny, 
		int maxIterations = MandelbrotSet::DEFAULT_NITERS, 
		int radius = MandelbrotSet::DEFAULT_RADIUS);
	~ThreadedMandelbrotSet();

	friend ostream& operator<<(ostream&, const ThreadedMandelbrotSet&); 
 
	void execAndWait(int m, int n);
	vvInt& getCounts(); 
	const vvInt& getCounts() const;
	double getElapsedTime() const;
	void writeImage(const string&);

private : 
	void getBoundsX(int ntx, int k, int& bx, int& ex) const;
	void getBoundsY(int nty, int k, int& by, int& ey) const;

	vvInt counts;
	double dx;
	double dy;
	int maxIterations;
	int nx;
	int ny;
	vvInt out;
	int radius;
	ThreadGroup tGroup;
	int threads;
	vector<vector<MandelbrotSet*>> vecMS;
	const cDouble& zCorner;
};