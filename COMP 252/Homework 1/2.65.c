#include <stdio.h>

int main() {
	unsigned int x = 0b01010101010101010101010101010101;
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	x &= 1;
	printf("%d\n", x);

	return 0;
}
