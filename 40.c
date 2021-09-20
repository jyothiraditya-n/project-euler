/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t count_digits(int64_t n) {
	int64_t digits = 0;
	while(n) { digits++; n /= 10; }
	return digits;
}

int64_t ten_pow(int64_t n) {
	int64_t prod = 1;
	for(int64_t i = 0; i < n; i++) prod *= 10;
	return prod;
}

int64_t get_digit(int64_t n) {
	int64_t value = 0;
	while(n > 0) n -= count_digits(++value);
	return (value / ten_pow(-n)) % 10;
}

int main() {
	int64_t prod = 1;
	for(int64_t i = 0; i <= 6; i++) prod *= get_digit(ten_pow(i));
	printf("%" PRId64 "\n", prod);
}