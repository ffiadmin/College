/**
 * Author      : Oliver Spryn
 * Course      : COMP 322, Advanced Programming 
 * Date        : 07 October 2013 
 * Description : This file declares the class which will later
 *               execute and store the results of executing
 *               the Mandelbrot algorithm.
*/

#include <complex>
#include <iostream>
#include <vector>

using std::complex;
using std::vector;

typedef complex<double> cDouble;
typedef vector<vector<int>> vvInt;

class MandelbrotSet { 
public : 
	static const int DEFAULT_NITERS = 150; 
	static const int DEFAULT_RADIUS = 3; 

	MandelbrotSet(const cDouble& zCorner, 
		double dx, double dy, int nx, int ny, 
		int maxIterations = DEFAULT_NITERS, 
		int radius = DEFAULT_RADIUS); 
	~MandelbrotSet(); 

	const vvInt& getCounts() const; 
	vvInt& getCounts(); 
	int iterate(const cDouble&);
	static unsigned __stdcall tfcn(void*);

private : 
	vvInt counts;
	double dx;
	double dy;
	int maxIterations;
	int nx;
	int ny; //I ♥ NY     :D
	int radius;
	const cDouble& zCorner;
};