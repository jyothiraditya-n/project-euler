/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

double fact(int64_t n) {
	double prod = 1;
	for(int64_t i = n; i > 0; i--) prod *= i;
	return prod;
}

double ncr(int64_t n, int64_t r) {
	return fact(n) / (fact(r) * fact(n - r));
}

int main() {
	int64_t count = 0;
	for(int64_t n = 1; n <= 100; n++)
		for(int64_t r = 0; r <= n; r++)
	{
		if(ncr(n, r) > 1000000) count++;
	}

	printf("%" PRId64 "\n", count);
	return 0;
}