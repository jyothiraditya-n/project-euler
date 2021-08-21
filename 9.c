/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

uint16_t a = 998;
uint16_t b = 1;
uint16_t c = 1;

void next() {
	b++; c--;
	
	if(b > c) {
		a--; b = 1; c = 999 - a;
	}

	return;
}

int main() {
	for(; (a * a) + (b * b) != (c * c); next());
	uint32_t product = a * b * c;

	printf("%" PRIu32 "\n", product);
	return 0;
}
