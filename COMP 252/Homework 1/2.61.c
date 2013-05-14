#include <stdio.h>

int main() {
//Part A
	int a = 0xF;
	int aa = 0;
	printf("%i\n", !!a);
	printf("%i\n", !!aa);

//Part B
	int b = 0xFFFFFFFF;
	int bb = 0;
	printf("%i\n", !!(~b));
	printf("%i\n", !!(~bb));

//Part C, must use unsigned integer
	unsigned int c = 0xABCDEF;
	unsigned int cc = 0;
	printf("%i\n", !!(c << (sizeof(c) * 8) - 8));
	printf("%i\n", !!(cc << (sizeof(cc) * 8) - 8));

//Part D, does not work with unsigned integer
	int d = 0xFFFFFFFF;
	int dd = 0;
	printf("%i\n", !!(~(d >> (sizeof(d) * 8) - 8)));
	printf("%i\n", !!(~(dd >> (sizeof(dd) * 8) - 8)));

	return 0;
}
