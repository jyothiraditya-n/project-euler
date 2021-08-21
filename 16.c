/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int main() {
	int64_t digits[4096] = {2};
	
	for(int64_t i = 1; i < 4096; i++) {
		digits[i] = 0;
	}
	
	for(int64_t i = 2; i <= 1000; i++) {
		for(int64_t j = 0; j < 4096; j++) {
			digits[j] *= 2;
		}
		
		for(int64_t j = 0; j < 4095; j++) {
			digits[j + 1] += digits[j] / 10;
			digits[j] %= 10;
		}
	}
	
	
	
	int64_t sum = 0;
	
	for(int64_t i = 0; i < 4096; i++) {
		sum += digits[i];
	}
	
	printf("%" PRId64 "\n", sum);
	return 0;
}
