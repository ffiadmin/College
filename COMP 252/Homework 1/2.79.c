#include <stdio.h>

void threefourths(int x);

int main() {
	threefourths(4);

	return 0;
};

void threefourths(int x) {
	x = x >> 1;
	x = x + (x << 1);

	printf("%i\n", x);
}
