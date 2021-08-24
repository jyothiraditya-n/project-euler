/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

bool sieve[10000000];

int64_t digit_length(int64_t n) {
	int64_t count = 0;
	while(n > 0) { n /= 10; count++; }
	return count;
}

int64_t check_rots(int64_t n) {
	int64_t len = digit_length(n);

	int64_t prod = 1;
	for(int64_t i = 1; i < len; i++) prod *= 10;

	for(int64_t i = 0; i < len; i++) {
		if(sieve[n]) return false;
		else n = (n / 10) + prod * (n % 10);
	}

	return true;
}

int main() {
	for(int64_t i = 2; i < 1000000; i++) {
		if(sieve[i]) continue;
		for(int64_t j = i * 2; j < 1000000; j += i)
			sieve[j] = true;
	}

	int64_t count = 0;

	for(int64_t i = 2; i < 1000000; i++)
		if(check_rots(i)) count++;

	printf("%" PRId64 "\n", count);
	return 0;
}