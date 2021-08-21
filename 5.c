/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

uint8_t missing_factor(uint32_t num, uint8_t divisor) {
	uint8_t i;
	for(i = 2; (num * i) % divisor != 0; i++);
	
	return i;
}

int main() {
	uint32_t num = 1;
	
	for(uint8_t i = 2; i <= 20; i++) {
		if(num % i != 0) num *= missing_factor(num, i);
	}
	
	printf("%" PRIu32 "\n", num);
	return 0;
}