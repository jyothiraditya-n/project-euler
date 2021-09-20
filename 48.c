/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t digits[11];
int64_t buf[11];

void compute(int64_t num) {
	for(int64_t i = 1; i < 10; i++) buf[i] = 0;
	buf[0] = 1;

	for(int64_t i = 0; i < num; i++) {
		for(int64_t i = 0; i < 10; i++) buf[i] *= num;

		for(int64_t i = 0; i < 10; i++) {
			buf[i + 1] += buf[i] / 10;
			buf[i] %= 10;
		}
	}

	for(int64_t i = 0; i < 10; i++) digits[i] += buf[i];
}

int main() {
	for(int64_t i = 1; i <= 1000; i++) compute(i);

	for(int64_t i = 0; i < 10; i++) {
		digits[i + 1] += digits[i] / 10;
		digits[i] %= 10;
	}

	for(int64_t i = 9; i >= 0; i--) printf("%" PRId64 "", digits[i]);
	putchar('\n');
}