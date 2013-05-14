#include <stdio.h>

typedef unsigned char* byte_pointer;

int is_little_endian();

int main() {
	if (is_little_endian()) {
		printf("Your processor is little endian or indian, or whatever\n");
	} else {
		printf("Your processor is big endian or indian, or whatever\n");
	}

	return 0;
}

int is_little_endian() {
	int x = 0x12345678;
	byte_pointer bp = (byte_pointer) &x;
	
	size_t size = snprintf(NULL, 0, "%.2x", bp[0]);
	char *buffer = malloc(size + 1);
	
	snprintf(buffer, size + 1, "%.2x", bp[0]);
	
	if (strcmp("78", buffer) == 0) {
		return 1;
	} else {
		return 0;
	}
}
