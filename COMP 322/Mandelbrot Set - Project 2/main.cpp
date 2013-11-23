
#include <iostream>
using std::cout;
using std::endl;

#include "ThreadedMandelbrotSet.h"

void testAll(ThreadedMandelbrotSet&);
void test(ThreadedMandelbrotSet&, int, int);

int main()
{
  // Sample dataset
  const int nx = 100;
  const int ny = 80;
  ThreadedMandelbrotSet tmset(Complex(-2.5, -2.),
                              0.05, 0.05, nx, ny);
  
  testAll(tmset);

  return 0;
}

void testAll(ThreadedMandelbrotSet& tmset)
{
  test(tmset, 1, 1);  //  1 thread
  test(tmset, 2, 1);  //  2 threads
  test(tmset, 2, 2);  //  4 threads
  test(tmset, 4, 2);  //  8 threads
  test(tmset, 4, 4);  // 16 threads
  test(tmset, 8, 4);  // 32 threads
  test(tmset, 8, 8);  // 64 threads
}

void test(ThreadedMandelbrotSet& tmset,
          int ntx, int nty)
{
  tmset.execAndWait(ntx, nty);
  double etime = tmset.getElapsedTime();
  
  cout << "Elapsed time with " << ntx*nty << " threads:  "
       << etime << " seconds" << endl;
}