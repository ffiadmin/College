/*
  Author:  Oliver Spryn & Dr. David Adams
  Course:  COMP 222, Data Structures
  Date:    4 April 2013
  Description:  This file implements the driver program for this assignment.
.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define USE_DFT

#include "Graph.h"

int main()
{
  cout << endl;
#ifdef USE_DFT
  cout << "-------------------------------" << endl;
  cout << "  Using depth-first traversal" << endl;
  cout << "-------------------------------" << endl;
#else
  cout << "---------------------------------" << endl;
  cout << "  Using breadth-first traversal" << endl;
  cout << "---------------------------------" << endl;
#endif // USE_DFT
  cout << endl;

  Graph graph("input.txt");
  cout << graph << endl;
  cout << endl;
  
  int start;
  cout << "Enter a start node:  " << endl;
  cin >> start;

  while (start >= 0)
  {
    cout << endl;

    int target;
    cout << "Enter a target node:  " << endl;
    cin >> target;
    cout << endl;

    int count;
    if (graph.search(count, start, target))
      cout << "Found Node " << target
           << " in " << count << " visits"
           << endl;
    else
      cout << "Node " << target
           << " not reachable from Node " << start
           << endl;
    cout << endl;

    cout << "Enter a start node:  " << endl;
    cin >> start;
  }

  return 0;
}
