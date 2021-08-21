/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

uint32_t int_sqrt(uint32_t num) {
	if(!num) return 0;
	
	uint32_t i;
	for(i = 1; i * i <= num; i++);
	
	return i - 1;
}

uint16_t factor_count(uint32_t num) {
	uint16_t total = 0;
	uint32_t limit = int_sqrt(num);

	for(uint32_t i = 1; i <= limit; i++) {
		if(num % i) continue;

		if(i == num / i) total++;
		else total += 2;
	}

	return total;
}

int main()
{
	uint32_t num = 0;
	
	for(uint16_t i = 1; factor_count(num) < 500; i++) {
		num += i;
	}
	
	printf("%" PRIu32 "\n", num);
	return 0;
}

