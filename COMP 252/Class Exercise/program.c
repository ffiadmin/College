#include <stdio.h>

int divide(int x, int y, int *remainder) {
	*remainder = 555;
	return x/y;
}

int main() {
	int rem;
	int quo = divide(8975, 47, &rem);
	printf("High word 0x%.8x, low word 0x%.8x\n", rem, quo);

	return 0;
}
