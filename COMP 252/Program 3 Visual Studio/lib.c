#define _CRT_SECURE_NO_DEPRECATE //Because *_s functions are MS only!!! Don't bug me please, compiler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "lib.h"

int isReference(char *string) {
	int length = strlen(string);
	
	return string[length - 1] == ':';
}

int isUDS(char *string) {
	return string[0] == '.';
}

int getOPData(char *OPCode) {
	int left = 0, right = OPTotal, middle = 0, cmp = 0;
	
	while (right >= left) {
		middle = (left + right) / 2;
		cmp = strcmp(OPCode, OPCodes[middle].name);
		
		if (cmp == 0) {
			return middle;
		} else if (cmp < 0) {
			right = middle - 1;
		} else {
			left = middle + 1;
		}
	}
	
	return -1;
}

int getRegData(char *RegCode) {
	int left = 0, right = RegTotal, middle = 0, cmp = 0;
	
	while (right >= left) {
		middle = (left + right) / 2;
		cmp = strcmp(RegCode, RegCodes[middle].name);
		
		if (cmp == 0) {
			return middle;
		} else if (cmp < 0) {
			right = middle - 1;
		} else {
			left = middle + 1;
		}
	}
	
	return -1;
}

int getUDS(char *UDSCode) {
	int i, cmp = 0;
	char code[8];

	strcpy(code, UDSCode + 1); //Strip off the "."
	
	for (i = 0; i < UDSTotal; ++i) {
		cmp = strcmp(code, UDSCodes[i].name);
		
		if (cmp == 0) {
			return i;
		}
	}

	return -1;
}

int getReference(char *RefCode) {
	int i, cmp = 0;
	char ref[10] = "";
	int length = strlen(RefCode);

	strcat(ref, RefCode);

	ref[length] = ':';

	for (i = 0; i < RefTotal; ++i) {
		cmp = strcmp(ref, RefCodes[i].name);

		if (cmp == 0) {
			return i;
		}
	}

	return -1;
}

int removeComments(char *inputName) {
	FILE *input, *output;
	char buffer;
	int comment = 0;

//Open the file streams
	input = fopen(inputName, "r");
	output = fopen("comments-removed.txt", "w");

//Check to see if file opening failed
	if (input == NULL) {
		printf("Failed to open input file for reading");
		return 0;
	}

//Check to see if file creation failed
	if (output == NULL) {
		printf("Failed to create a temporary file for writing");
		return 0;
	}

//Grab the first character
	buffer = fgetc(input);

//Iterate over each character in the file
	while (buffer != EOF) {
	//If comment mode is enabled, search through the characters set until '\n' is encountered
		if (comment) {
			if (buffer == '\n') {
				fprintf(output, "%c", '\n');
				comment = 0;
			}
		} else {
		//If this is the beginning of a comment, enable comment mode...
			if (buffer == '#') {
				comment = 1;
		//... otherwise print out the character to the output file stream
			} else {
				fprintf(output, "%c", buffer);
			}
		}

	//Grab the next chararcter
		buffer = fgetc(input);
	}

//Yeager, you need to close the files :D
	fclose(input);
	fclose(output);

	return 1;
}

int parseAndStoreUDS() {
	FILE *input, *output;
	char buffer;
	int UDS = 0, UDSVal = 1;
	char UDS1[16] = "its 2:15 AM now", UDS2[16] = "its a challenge";
	int UDS1Len = 0, UDS2Len = 0;
	
//Open the file streams
	input = fopen("comments-removed.txt", "r");
	output = fopen("UDS-parsed.txt", "w");
	
//Check to see if file opening failed
	if (input == NULL) {
		printf("Failed to open input file for reading");
		return 0;
	}

//Check to see if file creation failed
	if (output == NULL) {
		printf("Failed to create a temporary file for writing");
		return 0;
	}
	
//Grab the first character
	buffer = fgetc(input);
	
//Iterate over each character in the file
	while (buffer != EOF) {	
	//If UDS is enabled, search through the characters set until '\n' is encountered
		if (UDS) {
		//Part one of UDS, i.e. : ".pos" or ".stuff"
			if (UDS && UDSVal == 1) {
				if (buffer != ' ') {
					UDS1[UDS1Len] = buffer;
					UDS1[UDS1Len + 1] = '\0';
					UDS1Len++;

					fprintf(output, "%c", buffer); //Keep the name of the UDS in the file
				} else {
					UDSVal = 2; //We've moved past the ".pos" get ready for the value
				}
		//Part two of UDS, i.e. : 0x100, or whatever
			} else {
				if (buffer != '\n') {
					UDS2[UDS2Len] = buffer;
					UDS2[UDS2Len + 1] = '\0';
					UDS2Len++;
				} else {
				//Push the gathered data onto the UDS data array
					strcpy(UDSCodes[UDSTotal].name, UDS1);
					UDSCodes[UDSTotal++].address = (int)strtol(UDS2, NULL, 0);

				//Reset the counter values for any additional UDS
					UDSVal = 1; //We've got everything, exit UDS mode
					UDS = UDS1Len = UDS2Len = 0;

				//Keep the name of the UDS in the file
					fprintf(output, "%c", '\n');
				}
			}
		} else {
		//If this is the beginning of a UDS line, enable UDS mode...
			if (buffer == '.') {
				UDS = 1;
				fprintf(output, "%c", '.'); //Keep the name of the UDS in the file
		//... otherwise print out the character to the output file stream
			} else {
				fprintf(output, "%c", buffer);
			}
		}

	//Grab the next chararcter
		buffer = fgetc(input);
	}

//Yeager, you need to close the files :D
	fclose(input);
	fclose(output);
	
	return 1;
}

int generateAddressesAndStoreReferences() {
	FILE *input, *output;
	char buffer[100] = "";
	int status = 0;
	int index = 0;
	int start = UDSCodes[0].address; //.pos starting address
	int UDS; //Index of UDS in memory
	int roundOne = 1; //Don't increment the address during the first iteratation after each UDS

//Open the file streams
	input = fopen("UDS-parsed.txt", "r");
	output = fopen("OPS-only.txt", "w");

//Check to see if file opening failed
	if (input == NULL) {
		printf("Failed to open input file for reading");
		return 0;
	}

//Check to see if file creation failed
	if (output == NULL) {
		printf("Failed to create a temporary file for writing");
		return 0;
	}

//Grab the first string
	status = fscanf(input, "%s", buffer);

//Iterate over each string in the file
	while (status != EOF) {
		index = getOPData(buffer);

	//Is this string an OP code?
		if (index > -1) {
			if (roundOne) {
				roundOne = 0;
			} else {
				start += OPCodes[index].bytes; //Increment the total number of program bytes
			}

			fprintf(output, "\n%s", buffer);
		} else {
			if (isUDS(buffer)) {
				UDS = getUDS(buffer);
				start = UDSCodes[UDS].address;
				roundOne = 1;
			} else if (isReference(buffer)) {
				strcpy(RefCodes[RefTotal].name, buffer);
				RefCodes[RefTotal++].address = start;
			} else {
				fprintf(output, " %s", buffer);
			}
		}
		
	//Grab the next string
		status = fscanf(input, "%s", buffer);
	}
	
//Yeager, you need to close the files :D
	fclose(input);
	fclose(output);

	return 1;
}

int removeChars() {
	FILE *input, *output;
	char buffer = ' ';

//Open the file streams
	input = fopen("OPS-only.txt", "r");
	output = fopen("assembler-ready.txt", "w");

//Check to see if file opening failed
	if (input == NULL) {
		printf("Failed to open input file for reading");
		return 0;
	}

//Check to see if file creation failed
	if (output == NULL) {
		printf("Failed to create a temporary file for writing");
		return 0;
	}

//Grab the first character
	buffer = fgetc(input);

//Iterate over each string in the file
	while (buffer != EOF) {
		if (buffer == ',' || buffer == '(' || buffer == ')') {
			buffer = ' ';
		}

		fprintf(output, "%c", buffer);
		
	//Grab the next chararcter
		buffer = fgetc(input);
	}
	
//Yeager, you need to close the files :D
	fclose(input);
	fclose(output);

	return 1;
}

int assemble(char *outputFile) {
	FILE *input, *output;
	char buffer[100] = "";
	int status = 0;
	int OPLoc = 0, RegLoc1 = 0, RegLoc2 = 0, RefLoc = 0;
	char num1[12] = "", num2[12];
	char RefAddr[100] = "";

//Open the file streams
	input = fopen("assembler-ready.txt", "r");
	output = fopen(outputFile, "w");

//Check to see if file opening failed
	if (input == NULL) {
		printf("Failed to open input file for reading");
		return 0;
	}

//Check to see if file creation failed
	if (output == NULL) {
		printf("Failed to create output file for writing");
		return 0;
	}

//Grab the first string
	status = fscanf(input, "%s", buffer);

//Iterate over each string in the file
	while (status != EOF) {
		OPLoc = getOPData(buffer);

		switch(OPCodes[OPLoc].type) {
			case OP :
				fprintf(output, "%x%d\n", OPCodes[OPLoc].code, OPCodes[OPLoc].function);
				break;

			case RR : 
				status = fscanf(input, "%s", buffer);
				RegLoc1 = getRegData(buffer);
				status = fscanf(input, "%s", buffer);
				RegLoc2 = getRegData(buffer);

				fprintf(output, "%x%d %d%d\n", OPCodes[OPLoc].code, OPCodes[OPLoc].function, RegLoc1, RegLoc2);

				break;

			case RV :
				status = fscanf(input, "%s", buffer);
				RegLoc1 = getRegData(buffer);

				fprintf(output, "%x%d %dF\n", OPCodes[OPLoc].code, OPCodes[OPLoc].function, RegLoc1);

				break;

			case VR : 
				status = fscanf(input, "%s", buffer);
				numConvert1(buffer, num1);
				status = fscanf(input, "%s", buffer);
				RegLoc1 = getRegData(buffer);

				fprintf(output, "%x%d F%d %s\n", OPCodes[OPLoc].code, OPCodes[OPLoc].function, RegCodes[RegLoc1].code, num1);

				break;

			case RM : 
				status = fscanf(input, "%s", buffer);
				RegLoc1 = getRegData(buffer);
				status = fscanf(input, "%s", buffer);

				if (atoi(buffer)) {
					numConvert2(atoi(buffer), RefAddr);

					status = fscanf(input, "%s", buffer);
					RegLoc2 = getRegData(buffer);
				} else {
					numConvert2(0, RefAddr);

					status = fscanf(input, "%s", buffer);
					RegLoc2 = getRegData(buffer);
				}

				fprintf(output, "%x%d %d%d %s\n", OPCodes[OPLoc].code, OPCodes[OPLoc].function, RegLoc1, RegLoc2, RefAddr);


				break;

			case MR : 
				status = fscanf(input, "%s", buffer);

				if (atoi(buffer)) {
					numConvert2(atoi(buffer), RefAddr);

					status = fscanf(input, "%s", buffer);
					RegLoc1 = getRegData(buffer);
					status = fscanf(input, "%s", buffer);
					RegLoc2 = getRegData(buffer);
				} else {
					numConvert2(0, RefAddr);

					RegLoc1 = getRegData(buffer);
					status = fscanf(input, "%s", buffer);
					RegLoc2 = getRegData(buffer);
				}

				fprintf(output, "%x%d %d%d %s\n", OPCodes[OPLoc].code, OPCodes[OPLoc].function, RegLoc1, RegLoc2, RefAddr);

				break;

			case DEST : 
				status = fscanf(input, "%s", buffer);
				RefLoc = getReference(buffer);
				numConvert2(RefCodes[RefLoc].address, RefAddr);
				
				fprintf(output, "%x%d %s\n", OPCodes[OPLoc].code, OPCodes[OPLoc].function, RefAddr);

				break;

			default : 
				printf("Invalid op-code type encountered");
				return -1;
		}

	//Grab the next string
		status = fscanf(input, "%s", buffer);
	}
	
//Yeager, you need to close the files :D
	fclose(input);
	fclose(output);

	return 1;
}

int getNumber(char *number) {
	char *replaced = number + 1;
	
	return atoi(replaced);
}

void hexinator(int in, char *out) {
	char hex[10] = "";
	sprintf(hex, "%x", in);

	strcpy(out, hex);
}

void littleEndianinator(char *in, char *out) {
	int i, loc = 0;
	char endian[13] = "";

//Convert the integer into a character to swap around values
	char converted[9] = "";
	int length = strlen(in);

	for (i = 0; i < (8 - length); ++i) {
		converted[i] = '0';
	}

	strcat(converted, in);

//Swap around the characters
	for(i = 7; i >= 0; i -= 2) {
		endian[loc++] = converted[i - 1];
		endian[loc++] = converted[i];
		endian[loc++] = ' ';
	}

	endian[11] = '\0';
	strcpy(out, endian);
}

void numConvert1(char *in, char *out) {
	int value = getNumber(in);
	char hex[10] = "";
	char ret[12] = "";

	hexinator(value, hex);
	littleEndianinator(hex, ret);
	
	strcpy(out, ret);
}

void numConvert2(int in, char *out) {
	char hex[10] = "";
	char ret[12] = "";

	hexinator(in, hex);
	littleEndianinator(hex, ret);
	
	strcpy(out, ret);
}