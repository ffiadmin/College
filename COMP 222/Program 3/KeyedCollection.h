/*
  Author:  Oliver Spryn
  Course:  COMP 222, Data Structures
  Date:    Feb 19, 2013
  Description:  This file contains the implementation for the KeyedCollection
                class. There is no associated .cpp file, due to the added 
				complexity of templates with .cpp files. This class will simply
				maintain a vector of some set of keys and values.
*/

#include <algorithm>
#include <vector>
#include "Customer.h"

using namespace std;

template <class K, class T, bool BSEARCH = true> 
class KeyedCollection
{
public:
  // Create an empty collection
  KeyedCollection() {
	  cOp = 0;
	  cTotal = 0;
  }

  // Return the number of objects in the collection
  int size() const { return this->collection.size(); }

  // Insert object of type T with a key of type K into the
  // collection using an “ignore duplicates” policy
  void insert(const K& key, const T& type) {
	  if (!BSEARCH) {
		  if (std::find(keys.begin(), keys.end(), key) == keys.end()) {
			keys.push_back(key);
			collection.push_back(type);
		  }
	  } else {
		  int index = 0;

		//Find the index location where the key should be inserted
		  for(unsigned int i = 0; i < this->keys.size(); ++i) {
			  if (this->keys[i] == key) {
				  index = -1;
				  break; //Ignore duplicates
			  } else if (this->keys[i] > key) {
				  index = i;
				  break;
			  }
		  }

		  if (index != -1) {
			  if (keys.size() > 0) {
				  keys.insert(keys.begin() + index, key);
				  collection.insert(collection.begin() + index, type);
			  } else {
				  keys.push_back(key);
				  collection.push_back(type);
			  }
		  }
	  }
  }

  // Output data value of objects in the collection,
  // one data value per line
  friend ostream& operator<<(ostream& out, const KeyedCollection<K, T, BSEARCH>& k) {
	for (int i = 0; i < k.size(); i++) {
		out << k.keys[i] << " ";
		out << k.collection[i] << endl;
	}
	
	return out;
  }

  ////////////////////////////////////////////////////////////
  // New members

  // Return number of comparisons incurred by most recent
  // invocation of find
  int ncomp() const {
	  return cOp;
  }

  // Return total number of comparisons incurred since
  // creation of collection
  int ncompTotal() const {
	  return cTotal;
  }
  // Search the collection for specified key value
  //   if found
  //     populate parameter of type T with matching object
  //     return true
  //   else
  //     return false
  bool find(T& collection, const K& key) {
	  int left = 0, right = keys.size(), middle = 0;
	  cOp = 0; //Reset the counter

	  if(BSEARCH) {	
		while (right >= left) {
			middle = (left + right) / 2;
		
			if (keys[middle] == key) {
				cOp++;
				cTotal++;
				collection = this->collection[middle];
				return true;
			} else if (keys[middle] < key) {
				cOp++;
				cTotal++;
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}
	  } else {
		  for(int i = left; i < right; ++i) {
			  cOp++;
			  cTotal++;

			  if (keys[i] == key) {
				  collection = this->collection[i];
				  return true;
			  }
		  }
	  }

	  return false;
  }


private:
  vector<T> collection;
  vector<K> keys;

  int cTotal;
  int cOp;
};