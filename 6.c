/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h> 

int main() {
	uint32_t sum_of_squares = 0;
	uint32_t square_of_sums = 0;
	
	for(uint8_t i = 1; i <= 100; i++) {
		sum_of_squares += i * i;
		square_of_sums += i;
	}
	
	square_of_sums *= square_of_sums;
	
	printf("%" PRIu32 "\n", square_of_sums - sum_of_squares);
	return 0;
}
