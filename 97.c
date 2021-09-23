/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t digits[16];

int main() {
	digits[0] = 1;

	for(int64_t i = 0; i < 7830457; i++) {
		for(int64_t j = 0; j < 10; j++) digits[j] *= 2;

		for(int64_t j = 0; j < 10; j++) {
			digits[j + 1] += digits[j] / 10;
			digits[j] %= 10;
		}
	}

	for(int64_t i = 0; i < 10; i++) digits[i] *= 28433;

	for(int64_t i = 0; i < 10; i++) {
		digits[i + 1] += digits[i] / 10;
		digits[i] %= 10;
	}

	digits[0]++;

	for(int64_t i = 0; i < 10; i++) {
		digits[i + 1] += digits[i] / 10;
		digits[i] %= 10;
	}

	for(int64_t i = 9; i >= 0; i--) printf("%" PRId64 "", digits[i]);
	putchar('\n');
	return 0;
}