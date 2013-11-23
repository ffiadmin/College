/**
 * Author      : Oliver Spryn
 * Course      : COMP 322, Advanced Programming 
 * Date        : 31 October 2013 
 * Description : This file defines the complete functionality for the 
 *               the class which will execute the Threaded Mandelbrot algorithm
 *               and store the results of said process. 
*/

#include "ThreadedMandelbrotSet.h"

ThreadedMandelbrotSet::ThreadedMandelbrotSet(const cDouble& zCorner, 
		double dx, double dy, int nx, int ny, 
		int maxIterations, 
		int radius) : 
	zCorner(zCorner), 
	dx(dx), dy(dy), nx(nx), ny(ny), 
	maxIterations(maxIterations), 
	radius(radius) { }

ThreadedMandelbrotSet::~ThreadedMandelbrotSet() {
	
}

void ThreadedMandelbrotSet::execAndWait(int m, int n) {
//Calculate the number of threads
	threads = m * n;
	Complex corner;
	int bx = 0, by = 0, ex = 0, ey = 0;

//Allocate the proper memory
	vecMS.resize(n);

	for(int i = 0; i < n; ++i)
		vecMS[i].resize(m);

//Create the MandelBrot set obejcts
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			this->getBoundsX(m, j, bx, ex);
			this->getBoundsY(n, i, by, ey);

			Complex corner(this->zCorner.real() + bx*dx, this->zCorner.imag() + by*dy);
			vecMS[i][j] = new MandelbrotSet(corner, dx, dy, ey-by+1, ex-bx+1, maxIterations, radius);

			tGroup.add(MandelbrotSet::tfcn, (void*)vecMS[i][j]);
		}
	}

//Perform the calculation
	tGroup.execAndWait();

//Make this 2D array actually nice
	vvInt counts;
	out.resize(ny);

	for(int i = 0; i < ny; ++i)
		out[i].resize(nx);

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			counts = vecMS[i][j]->getCounts();
			this->getBoundsX(m, j, bx, ex);
			this->getBoundsY(n, i, by, ey);

			for(int k = by; k <= ey; ++k) {
				for(int l = bx; l <= ex; ++l) {
					out[k][l] = counts[k - by][l - bx];
				}
			}
		}
	}
}

void ThreadedMandelbrotSet::getBoundsX(int ntx, int k, int& bx, int& ex) const {
	bx = (nx / ntx) * k;
	if (k == ntx-1) {
		ex = nx-1;
	}
	else
	    ex = bx + (nx / ntx) - 1;
}

void ThreadedMandelbrotSet::getBoundsY(int nty, int k, int& by, int& ey) const {
	by = (ny / nty) * k;
	if (k == nty - 1) {
		ey = ny - 1;
	}
	else
		ey = by + (ny / nty) - 1;
}

const vvInt& ThreadedMandelbrotSet::getCounts() const {
	return this->counts;
}

vvInt& ThreadedMandelbrotSet::getCounts() {
	return this->counts;
}

double ThreadedMandelbrotSet::getElapsedTime() const {
	return tGroup.getElapsedTime() / 1000.0;
}

void ThreadedMandelbrotSet::writeImage(const string& name) {
	Image img(nx, ny);
	float red = 0.0f, green = 0.0f, blue = 0.0f;

	int mVal = 0;

	for(int i = 0; i < ny; ++i) {
		for(int j = 0; j < nx; ++j) {
			mVal = out[i][j];
			red = ((8*mVal)%256)/255.f; 
			green = ((16*mVal)%256)/255.f; 
			blue = ((32*mVal)%256)/255.f; 

			img.set(j, i, Color(red, green, blue));
		}
	}

	img.writeBMP(name);
}

ostream& operator<<(ostream& out, const ThreadedMandelbrotSet& mbs) {
	if (mbs.nx <= 10 && mbs.ny <= 10) {
		int mVal = 0;

		for(int i = 0; i < mbs.ny; ++i) {
			for(int j = 0; j < mbs.nx; ++j) {
				mVal = mbs.out[i][j];

				if (mVal >= 0 && mVal < 10) {
					out << "    " << mVal;
				} else if (mVal >= 10 && mVal < 100) {
					out << "   " << mVal;
				} else if (mVal >= 100 && mVal < 1000) {
					out << "  " << mVal;
				} else {
					out << " " << mVal;
				}
			}

			out << endl;
		}
	} else {
		int eTime = mbs.tGroup.getElapsedTime();

		out << "Test case 1: " << endl;
		out << mbs.nx * mbs.ny << " counts computed in " << eTime / 1000.0 << " seconds with ";
		out << mbs.threads << " threads." << endl;
	}

	return out;
}