/*
  Author:       Oliver J. Spryn
  Course:       COMP 252, Architecture & Organization
  Date:         12 February 2013
  Description:  This file contains the entire program. This program
  	  	  	  	prompts a user for a numerical value, then displays
  	  	  	  	its single and double precision floating point approx-
  	  	  	  	imations and also the 32 and 64-bit IEEE 754 binary
  	  	  	  	representations. This program will continue to prompt
  	  	  	  	a use for input and display the results until the
  	  	  	  	user types "e", in which case it will exit.
*/

#include <stdio.h>
#include <string.h>

#ifdef WIN32
#include <Windows.h>
#endif

void dumpBinaryByte(unsigned char x, int byte, int bits);
void _64BiBit(double doublePrecision);
void _32BiBit(float singlePrecision);

int main() {
	char input[81];

	while(TRUE) {
	//User prompt
		printf("Enter a number (e to exit): ");
		scanf("%s", input);

		if (strcmp(input, "e") == 0) {
			return 0;
		}

	//Display the input string
		printf("\nInput string:\n  %s\n\n", input);

	//Display the double precision floating point approximation
		double doublePrecision;
		sscanf(input, "%lf", &doublePrecision);
		printf("Double-precision floating point approximation:\n  %.17lf\n\n", doublePrecision);

	//Display the single precision floating point approximation
		float singlePrecision;
		sscanf(input, "%f", &singlePrecision);
		printf("Single-precision floating point approximation:\n  %.17f\n\n", singlePrecision);

	//Call helper a function to display the 64-bit IEEE 754 approximation
		printf("64-bit IEEE 754 binary representation:\n  ");
		_64BiBit(doublePrecision);

	//Call helper a function to display the 32-bit IEEE 754 approximation
		printf("\n\n32-bit IEEE 754 binary representation:\n  ");
		_32BiBit(singlePrecision);

		printf("\n\n");
	}

	return 0;
}

//Display and colorize the binary dump on a per byte basis
void dumpBinaryByte(unsigned char x, int byte, int bits) {
	int i;
	int counter = 1;
	int color = 0;

	for(i = 7; i >= 0; i --) {
	#ifdef WIN32
	//Generate the appropriate color for the outputted character, based on the 
	//position in the count and current byte number
		if (byte == 1) {
			if (counter == 1) {
				color = 12;
			} else {
				color = 9;
			}
		} else if (byte == 2) {
			if (counter == 1 || (bits == 64 && counter <= 4)) {
				color = 9;
			} else {
				color = 14;
			}
		} else {
			color = 14;
		}
		
	//Set the color
		HANDLE cHandle;
		cHandle = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(cHandle, color);

	//Display the bit for this iteration
		putchar((x >> i) % 2 == 0 ? '0' : '1');
		counter++;

	//Reset the text color
		SetConsoleTextAttribute(cHandle, 7);
	#else
	//Generate the appropriate color for the outputted character, based on the 
	//position in the count and current byte number
		if (byte == 1) {
			if (counter == 1) {
				printf("\033[31m");
			} else {
				printf("\033[34m");
			}
		} else if (byte == 2) {
			if (counter == 1 || (bits == 64 && counter <= 4)) {
				printf("\033[34m");
			} else {
				printf("\033[33m");
			}
		} else {
			printf("\033[33m");
		}

	//Display the bit for this iteration
		putchar((x >> i) % 2 == 0 ? '0' : '1');
		counter++;
		
	//Reset the text color
		printf("\033[31m");
	#endif
	}
}

void _64BiBit(double doublePrecision) {
//Cast the double to an unsigned char
	double* DPPtr;
	unsigned char* DPIPtr;
	DPPtr = &doublePrecision;
	DPIPtr = (unsigned char*) DPPtr;

//Iterate through each byte of the double using pointer arithmetic and use a helper function to dump the bits
	int i;
	int byte = 1;
	for(i = sizeof(double)-1; i >= 0; i --) {
		dumpBinaryByte(DPIPtr[i], byte, 64);
		byte++;
	}
}

void _32BiBit(float singlePrecision) {
//Cast the double to an unsigned char
	float* SPPtr;
	unsigned char* SPIPtr;
	SPPtr = &singlePrecision;
	SPIPtr = (unsigned char*) SPPtr;

//Iterate through each byte of the double using pointer arithmetic and use a helper function to dump the bits
	int i;
	int byte = 1;
	for(i = sizeof(float)-1; i >= 0; i --) {
		dumpBinaryByte(SPIPtr[i], byte, 32);
		byte++;
	}
}