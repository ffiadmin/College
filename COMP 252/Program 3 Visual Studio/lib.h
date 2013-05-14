#ifndef __LIB_H
#define __LIB_H

int isReference(char *string);
int isUDS(char *string);

int getOPData(char *OPCode);
int getRegData(char *RegCode);
int getUDS(char *UDSCode);
int getReference(char *RefCode);

int removeComments(char *inputName);
int parseAndStoreUDS();
int generateAddressesAndStoreReferences();
int removeChars();
int assemble(char *outputName);

int getInt(char *number);
void hexinator(int in, char *out);
void littleEndianinator(char *in, char *out);
void numConvert1(char *in, char *out);
void numConvert2(int in, char *out);

#endif