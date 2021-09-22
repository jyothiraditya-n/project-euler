/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t digits[256];

int64_t digit_sum(int64_t a, int64_t b) {
	for(int64_t i = 1; i < 256; i++) digits[i] = 0;
	digits[0] = 1;

	for(int64_t i = 0; i < b; i++) {
		for(int64_t j = 0; j < 256; j++) digits[j] *= a;

		for(int64_t i = 0; i < 255; i++) {
			digits[i + 1] += digits[i] / 10;
			digits[i] %= 10;
		}
	}

	int64_t sum = 0;
	for(int64_t i = 0; i < 256; i++) sum += digits[i];
	return sum;
}

int main() {
	int64_t max = 0;

	for(int64_t a = 1; a < 100; a++)
		for(int64_t b = 1; b < 100; b++)
	{
		int64_t sum = digit_sum(a, b);
		if(sum > max) max = sum;
	}

	printf("%" PRId64 "\n", max);
}