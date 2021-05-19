#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

uint32_t primes[10001] = {2, 3};
uint16_t last = 1;

bool isprime(uint32_t n) {
	uint16_t i = 0;
	uint32_t prime = primes[i];

	while(prime) {
		if(n % prime == 0) return false;

		i++;
		prime = primes[i];

	}

	return true;
}

void find_prime() {
	uint32_t number;
	for(number = primes[last] + 2; !isprime(number); number += 2);

	last++;
	primes[last] = number;
	
	return;
}

int main() {
	for(uint16_t i = 1; i < 10001; i++) {
		find_prime();
	}
	
	printf("%" PRIu32 "\n", primes[10000]);
	return 0;
}