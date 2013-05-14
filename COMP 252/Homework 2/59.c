#include <stdio.h>
int switch_prob(int x, int n);

int main() {
	
	
	return 0;
}

int switch_prob(int x, int n) {
	int result = x;
	//Sets up jump table
	//Computes n - 50
	//Compare index 5 in table
	
	switch(n) {
		case 50 : 
		case 52 : 
			x << 2;
			goto end;
		
		case 53 : 
			x >> 2;
			break;
			
		case 54 : 
			x = 3*x;
			x *= x;
			//fall through
			
		case 55 : 
		default : 
		end:
			x += 0xA;
	}
	
	return result;
}
