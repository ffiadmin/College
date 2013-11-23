
#include <iostream>
using std::cout;
using std::endl;

#include "ThreadedMandelbrotSet.h"

void render(const Complex&, double, double, int, int,
            const string&, int, int, int, int);

int main()
{
  const int ntx = 2;
  const int nty = 2;

//Required image 1
  Complex corner(-2.5, -2.);
  double  dx     = 0.005;
  double  dy     = 0.005;
  int     xres   = 1000;
  int     yres   = 800;
  string  name   = "required-1.bmp";
  int     niters = 256;
  int     radius = 3;

//Required image 2
 /*
  Complex corner(0.338694, 0.072486);
  double  dx     = 1.48582e-7;
  double  dy     = 2.018253e-7;
  int     xres   = 1024;
  int     yres   = 768;
  string  name   = "required-2.bmp";
  int     niters = 256;
  int     radius = 3;
  */

//Fun image 1
  /*
  Complex corner(0.338694, 0.072486);
  double  dx     = 1.e-5;
  double  dy     = 1.e-5;
  int     xres   = 1024;
  int     yres   = 768;
  string  name   = "awesome-1.bmp";
  int     niters = 256;
  int     radius = 3;
  */

//Fun image 2
  /*
  Complex corner(-0.7, -0.7);
  double  dx     = 0.0002;
  double  dy     = 0.0002;
  int     xres   = 1024;
  int     yres   = 768;
  string  name   = "awesome-2.bmp";
  int     niters = 256;
  int     radius = 5;
  */
  render(corner, dx, dy, xres, yres, name, ntx, nty, niters, radius);

  return 0;
}

void render(const Complex& corner, double dx, double dy,
            int nx, int ny, const string& fname, int ntx,
            int nty, int niters, int radius)
{

  ThreadedMandelbrotSet tmset(corner, dx, dy, nx, ny, niters, radius);
  tmset.execAndWait(ntx, nty);

  double etime = tmset.getElapsedTime();

  cout << "Elapsed time with " << ntx << "x" << nty
       << " threads:  " << etime << " seconds" << endl;

  cout << "Writing image to \"" << fname << "\"... ";
  tmset.writeImage(fname);
  cout << "done" << endl;
  cout << endl;
}