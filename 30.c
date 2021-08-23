/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t raise(int64_t a, int64_t b) {
	int64_t prod = 1;
	for(int64_t i = 0; i < b; i++) prod *= a;
	return prod;
}

int64_t reconstruct(int64_t n) {
	int64_t sum = 0;
	while(n) { sum += raise(n % 10, 5); n /= 10; }
	return sum;
}

int main() {
	int64_t sum = 0;
	for(int64_t i = 2; i <= 295245; i++)
		if(reconstruct(i) == i) sum += i;

	printf("%" PRId64 "\n", sum);
	return 0;
}