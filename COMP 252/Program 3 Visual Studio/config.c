#include "config.h"
	
//Register all OP-codes
	struct OPData OPCodes[] = {
		{"addl",   2, 6,   0, RR},
		{"andl",   2, 6,   2, RR},
		{"call",   5, 8,   0, DEST},
		{"cmove",  2, 2,   3, RR},
		{"cmovg",  2, 2,   6, RR},
		{"cmovge", 2, 2,   5, RR},
		{"cmovl",  2, 2,   2, RR},
		{"cmovle", 2, 2,   1, RR},
		{"cmovne", 2, 2,   4, RR},
		{"halt",   1, 0,   0, OP},
		{"irmovl", 6, 3,   0, VR},
		{"je",     5, 7,   3, DEST},
		{"jg",     5, 7,   6, DEST},
		{"jge",    5, 7,   5, DEST},
		{"jl",     5, 7,   2, DEST},
		{"jle",    5, 7,   1, DEST},
		{"jmp",    5, 7,   0, DEST},
		{"jne",    5, 7,   4, DEST},
		{"mrmovl", 6, 5,   0, MR},
		{"nop",    1, 1,   0, OP},
		{"popl",   2, 0xB, 0, RV},
		{"pushl",  2, 0xA, 0, RV},
		{"ret",    1, 9,   0, OP},
		{"rmmovl", 6, 4,   0, RM},
		{"rrmovl", 2, 2,   0, RR},
		{"subl",   2, 6,   1, RR},
		{"xorl",   2, 6,   3, RR}
	};
	
	int OPTotal = sizeof(OPCodes) / sizeof(struct OPData);
	
//Register all registers (it's kinda like Inception)
	struct RegData RegCodes[] = {
		{"%eax", 0},
		{"%ebp", 5},
		{"%ebx", 3},
		{"%ecx", 1},
		{"%edi", 7},
		{"%edx", 2},
		{"%esi", 6},
		{"%esp", 4}
	};
	
	int RegTotal = sizeof(RegCodes) / sizeof(struct RegData);

//Initialize other variables
	int UDSTotal = 0;
	int RefTotal = 0;