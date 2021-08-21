/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t digits[4096];

int main() {
	for(int64_t i = 0; i < 4096; i++) digits[i] = 0;
	digits[0] = 1;
	
	for(int64_t i = 1; i <= 100; i++) {
		for(int64_t j = 0; j < 4096; j++) {
			digits[j] *= i;
		}
		
		for(int64_t j = 0; j < 4095; j++) {
			digits[j + 1] += digits[j] / 10;
			digits[j] = digits[j] % 10;
		}
	}
	
	int64_t sum = 0;
	for(int64_t i = 0; i < 4096; i++) sum += digits[i];
	
	printf("%" PRId64 "\n", sum);
	return 0;
}
