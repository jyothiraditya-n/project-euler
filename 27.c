/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

bool isprime(int16_t n) {
	if(n <= 1) return false;

	if(n == 2) return true;
	if(n % 2 == 0) return false;

	for(int16_t i = 3; i < n; i += 2) {
		if(n % i == 0) return false;
	}

	return true;
}

uint16_t prime_count(int16_t a, int16_t b) {
	uint16_t n;
	for(n = 0; isprime(n * n + a * n + b); n++);

	return n;
}

uint16_t best = 0;
int32_t product = 0;

void check_better(int16_t a, int16_t b) {
	uint16_t count = prime_count(a, b);

	if(count > best) {
		best = count;
		product = a * b;
	}

	return;
}

int main() {
	for(int16_t a = -999; a < 1000; a++)
		for(int16_t b = -1000; b <= 1000; b++)
	{
		check_better(a, b);
	}

	printf("%" PRId32 "\n", product);
	return 0;
}