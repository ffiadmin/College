/*
  Author:  Oliver Spryn
  Course:  COMP 222, Data Structures
  Date:    4 April 2013
  Description:  This file implements the Graph ADT for the assignment, and all of the necessary
                properties expected of this ADT.
*/

#include <fstream>
#include <iostream>

#include "Graph.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

Graph::Graph(const string &file) {
	int from, to;
	ifstream fin;
	fin.open(file);

	if (fin.fail()) {
		cout << file << " could not be opened" << endl;
		exit(1);
	}
	
	while (!fin.eof()) {
		fin >> from >> to;
		this->addNode(from, to);
	}

	fin.close();
	this->removeDups();
}

void Graph::addNode(int from, int to) {
//Check to see if the "from" node exists
	this->allocateSize(from + 1);
	
//Add the new node onto the end of the list
	if (from != to)
		this->nodes[from] = new Node(to, this->nodes[from]);
	
//Check to see if the "to" node exists
	this->allocateSize(to + 1);

//Add the new node onto the end of the list
	if (to != from)
		this->nodes[to] = new Node(from, this->nodes[to]);
}

void Graph::allocateSize(int size) {
	if (this->nodes.size() <= size) {
		this->nodes.resize(size);
	}
}

void Graph::removeDups() {
	Node *item, *prev = new Node();
	int seen[100], max = 0;

	for (int i = 0; i < 100; ++i) {
		seen[i] = 0;
	}

	for(int i = 0; i < this->nodes.size(); ++i) {
		item = this->nodes[i];

		while (item != NULL) {
		//If this value in the array is 0, then it has not been encountered yet
			if (seen[item->data] == 0) {
				seen[item->data] = 1;
				prev = item;
		//If it has been encountered, blast it away with your linked list gun
			} else {
				prev->next = item->next;
			}

			max = item->data > max ? item->data : max;
			item = item->next;
		}

		for (int i = 0; i <= max; ++i) {
			seen[i] = 0;
		}

		max = 0;
		prev = new Node();
	}
}

bool Graph::search(int &count, int start, int target) const {
	if (start > this->nodes.size() - 1 || start < 0
		|| target > this->nodes.size() - 1 || target < 0) {
		return false;
	}

//#ifdef USE_DFT
	//return this->searchDFS(count, start, target);
//#else
	return this->searchBFS(count, start, target);
//#endif
}

bool Graph::searchBFS(int &count, int start, int target) const {
	vector<Node*> queue;
	visited.
	queue.push_back(this->nodes[start]);

	while(!queue.empty()) {

	}

	/*
	queue<Node*> open;
	queue<Node*> closed;
	Node* temp;
	count++;

	open.push(this->nodes[start]);

	while(!open.empty()) {
		temp = open.back();
		open.pop();
		closed.push(temp);

		if (temp->data == target) {
			count++;
			cout << "Traversing: " << start;

			for(int i = 0; i <= count - 1; ++i) {
				temp = closed.back();
				closed.pop();
				cout << " " << temp;
			}

			cout << " " << target << endl;

			return true;
		}

		while(temp != NULL) {
			temp = temp->next;
			open.push(temp);
			count++;
		}
	}

	/*
	queue<Node*> Q;
	vector<int> mark;
	Node* temp;

	Q.push(this->nodes[start]);
	mark.push_back(start);

	while(!Q.empty()) {
		temp = Q.back();
		Q.pop();
		count++;

		if (temp->data == target) {
			cout << "Traversing: " << start;

			for(int i = 0; i <= count; ++i) {
				cout << " " << mark[i];
			}

			cout << endl;

			return true;
		}

		while(temp != NULL) {
			if (std::find(mark.begin(), mark.end(), temp->data) == mark.end()) {
				mark.push_back(temp->data);
				Q.push(this->nodes[temp->data]);
			}
		}

		cout << "HI ";
	}

	return false;

	/*int internalCount = 0, seen[100];

	if (start == target && this->nodes[start] != NULL) {
		cout << "Traversing: " << start << " " << start << endl;
		count = 1;
		return true;
	}

	for (int i = 0; i < 100; ++i) {
		seen[i] = -1;
	}

	if (start <= this->nodes.size()) {
		for (Node *item = this->nodes[start]; item != NULL; item = item->next, ++internalCount) {
			seen[internalCount] = item->data;

			if (item->data == target) {
				cout << "Traversing: " << start;

				for(int j = 0; j <= internalCount; ++j) {
					cout << " " << seen[j];
				}

				cout << endl;

				count = internalCount + 2; //+1 for this iteration and +1 for the starting node

				return true;
			}
		}
	}

	return false;*/
}

bool Graph::searchDFS(int &count, int start, int target) const {
//Containers
	vector<int> visit;
	stack<int> stack;
	Node* temp;

	stack.push(start);
	visit.push_back(start);

	cout << "Traversing:";

	while(!stack.empty()) {
		cout << " " << visit.back();
		temp = this->nodes[stack.top()];

		while(temp->next != NULL) {
			if (std::find(visit.begin(), visit.end(), temp->data) != visit.end()) {
				stack.pop();
				break;
			} else {
				stack.push(temp->data);
				visit.push_back(temp->data);
			}
		}
	}

	cout << " " << visit.back();
	count = visit.size();

	return true;
	/*
//Containers and the like
	stack<DFSData*> stack;
	vector<int> discovered;
	vector<int> explored;
	DFSData* tempDFS;
	Node* tempN;
	int counter = 0;
	bool found = false;

//Label the start item as discovered and start exploring from here
	discovered.push_back(start);
	stack.push(new DFSData(start, 1));

	if (this->nodes[start] == NULL || this->nodes[target] == NULL) {
		return false;
	}

	if (start < target) {
		for(int i = start; i <= target; ++i) {
			if(this->nodes[i] == NULL) return false;
		}
	} else {
		for(int i = target; i <= start; ++i) {
			if(this->nodes[i] == NULL) return false;
		}
	}

	while (!stack.empty()) {
		tempDFS = stack.top();

	//We've got 'em!
		if (tempDFS->index == target) {
			cout << "Traversing: ";

			for(int i = 0; i < discovered.size(); ++i) {
				cout << " " << discovered[i];
			}

			cout << endl;

			count = ++counter;
			return true;
		}

		tempN = this->nodes[tempDFS->index];

	//Nope, start exploring
		found = false;
		tempN = this->nodes[tempDFS->index];

		while (tempDFS != NULL) {
		//Have we explored or discovered this item?
			if (std::find(discovered.begin(), discovered.end(), tempDFS->index) != discovered.end() &&
				std::find(explored.begin(), explored.end(), tempDFS->index) != explored.end()) {
				found = true;
				tempN = tempN->next;
			} else {
				break;
			}
		}

		if (!found) {
			stack.push(new DFSData(tempN->data, 1));
			discovered.push_back(tempN->data);
		} else {
			tempDFS->status = 2;
			stack.pop();
		}

		counter++;
	}

	/*vector<DFSData*> S;
	vector<int> seen;
	DFSData *c;
	Node *temp;
	bool found;
	int internalCount = 0;
	S.push_back(new DFSData(start, 1));
	seen.push_back(start);

	if (this->nodes[start] == NULL || this->nodes[target] == NULL) {
		return false;
	}

	if (start < target) {
		for(int i = start; i <= target; ++i) {
			if(this->nodes[i] == NULL) return false;
		}
	} else {
		for(int i = target; i <= start; ++i) {
			if(this->nodes[i] == NULL) return false;
		}
	}
	
	while(!S.empty()) {
		c = S.back();

		if (c->index == target) {
			cout << "Traversing:";

			for(int i = 0; i < seen.size(); ++i) {
				cout << " " << seen[i];
			}

			cout << endl;

			count = ++internalCount;
			return true;
		}

	//Is there an adjacent node that we haven't yet explored?
		found = false;
		temp = this->nodes[c->index];

		while(temp != NULL) { //All adjacent items
			for (int i = 0; i < S.size(); ++i) { //All items in stack
				if (temp->data == S[i]->index) { //This item exists in the stack, skip it
					found = true;
					break;
				}
			}

			if (!found) {
				break;
			}

			temp = temp->next;
			found = false;
		}

		if (!found) {
			S.push_back(new DFSData(temp->data, 1));
			seen.push_back(temp->data);
		} else {
			c->status = 2;
			S.pop_back();
		}

		++internalCount;
	}

	return false;*/
}

int Graph::size() const {
	return this->nodes.size();
}

ostream& operator<<(ostream &out, const Graph &object) {
	const Node *next;

	for(int i = 0; i < object.nodes.size(); ++i) {
		next = object.nodes[i];

		if (next != NULL) {
			out << i << ":";

			while (next != NULL) {
				out << " " << next->data;
				next = next->next;
			}

			out << endl;
		}
	}

	return out;
}