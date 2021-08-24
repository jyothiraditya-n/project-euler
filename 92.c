/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t sumofdigs(int64_t n) {
	int64_t sum = 0;
	
	while(n > 0) {
		int64_t mod = n % 10;
		sum += mod * mod;
		n /= 10;
	}

	return sum;
}

int64_t endof(int64_t n) {
	while(n != 1 && n != 89) n = sumofdigs(n);
	return n;
}

int main() {
	int64_t sum = 0;
	for(int64_t i = 1; i < 10000000; i++)
		if(endof(i) == 89) sum++;

	printf("%" PRId64 "\n", sum);
	return 0;
}