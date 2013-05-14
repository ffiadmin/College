#include <iostream>
#include <time.h>
using namespace std;
	
static const int N = 1000000;
	
int main()  {
	int i, j, p, q;
	int* id = new int[N];
	int* sz = new int[N];
	int counter = 0;
	
	srand(time(0));
	unsigned int myRand1, myRand2;
	int unions = 0;
	
	for (i = 0; i < N; i++){
		id[i] = i; sz[i] = 1;
	}
	   
	while (unions <= N - 1) {
		counter ++;

	//Generate a 32-bitish random number
		myRand1 = rand();
		myRand1 = (myRand1 << 16) | rand();
		myRand1 = (myRand1 % (N - 1)) + 1;
			
		myRand2 = rand();
		myRand2 = (myRand2 << 16) | rand();
		myRand2 = (myRand2 % (N - 1)) + 1;
			
		for (i = myRand1; i != id[i]; i = id[i])
			id[i] = id[id[i]];
		for (j = myRand2; j != id[j]; j = id[j])
			id[j] = id[id[j]];
	
		if (i == j) continue;
	
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
			unions++;
		} else {
			id[j] = i;
			sz[i] += sz[j];
			unions++;
		}
	
		cout << unions << " " << counter << endl;
	}
	
	delete [] id;
	delete [] sz;
	
	return 0;
}

/*
#include <iostream>
#include <time.h>
using namespace std;
	
static int N = 0;
	
int main()  {
	int i, j, p, q;
	int* id = new int[N];
	int* sz = new int[N];
	unsigned int myRand1, myRand2;
	int unions = 0;
	int counter = 0;
	 
	for(N = 100; N <= 1000; N++) {
		id = new int[N];
		sz = new int[N];
		counter ++;

		srand(time(0));
	
		for (i = 0; i < N; i++){
			id[i] = i; sz[i] = 1;
		}

	//Generate a 32-bitish random number
		myRand1 = rand();
		myRand1 = (myRand1 << 16) | rand();
		myRand1 = (myRand1 % (N - 1)) + 1;
			
		myRand2 = rand();
		myRand2 = (myRand2 << 16) | rand();
		myRand2 = (myRand2 % (N - 1)) + 1;
			
		for (i = myRand1; i != id[i]; i = id[i])
			id[i] = id[id[i]];
		for (j = myRand2; j != id[j]; j = id[j])
			id[j] = id[id[j]];
	
		if (i == j) continue;
	
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
			unions++;
		} else {
			id[j] = i;
			sz[i] += sz[j];
			unions++;
		}
	
		cout << counter << endl;

		delete [] id;
		delete [] sz;
	}
	
	return 0;
}
*/