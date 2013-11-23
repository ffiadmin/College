/**
 * Author      : Oliver Spryn
 * Course      : COMP 322, Advanced Programming 
 * Date        : 07 October 2013 
 * Description : This file defines the complete functionality for the 
 *               the class which will execute the Mandelbrot algorithm
 *               and store the results of said process. 
*/

#include "MandelbrotSet.h"

using std::abs;

MandelbrotSet::MandelbrotSet(const cDouble& zCorner, 
		double dx, double dy, int nx, int ny, 
		int maxIterations, 
		int radius) : 
	zCorner(zCorner), 
	dx(dx), dy(dy), nx(nx), ny(ny), 
	maxIterations(maxIterations), 
	radius(radius)
{
	this->counts.resize(this->nx);

	for(int i = 0; i < this->nx; ++i)
		for(int j = 0; j < this->ny; ++j)
			this->counts[i].push_back(0);
}

MandelbrotSet::~MandelbrotSet() { }

const vvInt& MandelbrotSet::getCounts() const {
	return this->counts;
}

vvInt& MandelbrotSet::getCounts() {
	return this->counts;
}

int MandelbrotSet::iterate(const cDouble& c) {
	cDouble z(0, 0);
	int count = 0;

	while(abs(z) < this->radius && count < this->maxIterations) {
		z *= z;
		z += c;
		++count;
	}
	
	return count;
}

unsigned __stdcall MandelbrotSet::tfcn(void* MandelbrotObj) {
	MandelbrotSet *ms = (MandelbrotSet*)MandelbrotObj;
	cDouble incX(ms->dx, 0);
	cDouble incY(0, ms->dy);
	
	for(int i = 0; i < ms->nx; ++i)
		for(int j = 0; j < ms->ny; ++j)
			ms->counts[i][j] = ms->iterate(ms->zCorner + incX * (double)j + incY * (double)i);
	
	return 0;
}