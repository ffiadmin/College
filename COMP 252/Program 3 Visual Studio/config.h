#ifndef __CONFIG_H
#define __CONFIG_H

//Define an enumerated type which will identify the OP-code type
	enum Type {
		OP,   //Op-code only
		RR,   //Register-register
		RV,   //Register-value
		VR,   //Value-register
		RM,   //Register-memory
		MR,   //Memory-register (not Mister)
		DEST  //Destination
	};

//Define the OP-code structure
	struct OPData {
		char *name;
		int bytes;
		int code, function;
		enum Type type;
	};
	
//Register all OP-codes
	struct OPData OPCodes[];
	int OPTotal;
	
//Define the register structure
	struct RegData {
		char *name;
		int code;
	};
	
//Register all registers (it's kinda like Inception)
	struct RegData RegCodes[];
	int RegTotal;

//Define the UDS structure
	struct UDSData {
		char name[8];
		int address;
	};

	struct UDSData UDSCodes[10000];
	int UDSTotal;

//Define the reference structure
	struct RefData {
		char name[10];
		int address;
	};

	struct RefData RefCodes[10000];
	int RefTotal;

#endif