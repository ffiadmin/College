/*
  Author:  Oliver Spryn
  Course:  COMP 222, Data Structures
  Date:    4 April 2013
  Description:  This file defines the Graph ADT for the assignment.
*/

#ifndef Graph_h
#define Graph_h

#include <algorithm>
#include <iosfwd>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define USE_DFT

using std::ostream;
using std::queue;
using std::stack;
using std::string;
using std::vector;

struct Node {
	Node() : data(-1), next(NULL), visited(false), index(-1) {}
	Node(int data, Node *next) : data(data), next(next), visited(false), index(-1) {}
	int data;
	Node *next;
	bool visited;
	int index;
};

struct DFSData {
	DFSData() : index(0), status(0) {}
	DFSData(int index, int status) : index(index), status(status) {}
	int index;
	int status;
};

class Graph {
public : 
	Graph(const string& file);
	int size() const;
	bool search(int &count, int start, int target) const;
	
	friend ostream& operator<<(ostream&, const Graph&);
	
private : 
	vector<Node*> nodes;

	void addNode(int from, int to);
	void allocateSize(int size);
	bool thereYet(int index, int item);
	bool searchBFS(int &count, int start, int target) const;
	bool searchDFS(int &count, int start, int target) const;
};
#endif