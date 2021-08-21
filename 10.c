/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

bool nonprime[2000000];

void rm_multiples(uint32_t n) {
	if(nonprime[n]) return;
	
	for(uint32_t i = n * 2; i < 2000000; i += n) {
		nonprime[i] = true;
	}

	return;
}

int main() {
	uint64_t sum = 0;

	for(uint32_t i = 2; i < 2000000; i++) {
		rm_multiples(i);
	}

	for(uint32_t i = 2; i < 2000000; i++) {
		if(!nonprime[i]) sum += i;
	}
	
	printf("%" PRIu64 "\n", sum);
	return 0;
}