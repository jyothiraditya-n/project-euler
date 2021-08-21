/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int main() {
	uint32_t two_back = 1;
	uint32_t one_back = 1;
	uint32_t current = 2;

	uint32_t sum = 0;
	
	while(current <= 4000000) {
		if(current % 2 == 0) sum += current;

		two_back = one_back;
		one_back = current;
		current = two_back + one_back;
	}
	
	printf("%" PRIu32 "\n", sum);
	return 0;
}
