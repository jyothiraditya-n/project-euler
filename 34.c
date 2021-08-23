/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t factorial(int64_t a) {
	int64_t prod = 1;
	while(a > 1) prod *= a--;
	return prod;
}

int64_t reconstruct(int64_t n) {
	int64_t sum = 0;
	while(n) { sum += factorial(n % 10); n /= 10; }
	return sum;
}

int main() {
	int64_t sum = 0;
	for(int64_t i = 3; i <= 10000000; i++)
		if(reconstruct(i) == i) sum += i;

	printf("%" PRId64 "\n", sum);
	return 0;
}