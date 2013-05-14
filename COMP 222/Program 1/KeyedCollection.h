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

template <class K, class T> 
class KeyedCollection
{
public:
  // Create an empty collection
  KeyedCollection() {
	  
  }

  // Return the number of objects in the collection
  int size() const { return this->collection.size(); }

  // Insert object of type T with a key of type K into the
  // collection using an “ignore duplicates” policy
  void insert(const K& key, const T& type) {
	  if (find(keys.begin(), keys.end(), key) == keys.end()) {
	    keys.push_back(key);
	    collection.push_back(type);
	  }
  }

  // Output data value of objects in the collection,
  // one data value per line
  friend ostream& operator<<(ostream& out, const KeyedCollection<K, T>& k) {
	for (int i = 0; i < k.size(); i++) {
		out << k.keys[i] << " ";
		out << k.collection[i] << endl;
	}
	
	return out;
  }

private:
  vector<T> collection;
  vector<K> keys;
};