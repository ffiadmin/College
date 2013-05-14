#define _CRT_SECURE_NO_DEPRECATE //Because *_s functions are MS only!!! Don't bug me please, compiler
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "config.h"
#include "lib.h"

int main(int argc, char **argv) {
//Check to see if the approparite number of program arguments have been recieved
	if (argc != 3) {
		printf("Oh my beans! Usage: ./tokenize inputfile.txt. outputfile.txt\n");
		return 1; //Why no exit(1)? :'-( <-- Because this is C, Oliver. <-- Ok, thanks.
	}

//Bootstrap this program's processes
	removeComments(argv[1]);
	parseAndStoreUDS();
	generateAddressesAndStoreReferences();
	removeChars();
	assemble(argv[2]);
	
	return 0;
}