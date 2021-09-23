/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

int64_t count_a[10] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
int64_t count_b[10];

void load_a(int64_t num) {
	for(int64_t i = 0; i < 10; i++) count_a[i] = 0;
	while(num) { count_a[num % 10]++; num /= 10; }
}

bool compare(int64_t num) {
	for(int64_t i = 0; i < 10; i++) count_b[i] = 0;
	while(num) { count_b[num % 10]++; num /= 10; }

	for(int64_t i = 0; i < 10; i++)
		if(count_a[i] != count_b[i]) return false;

	return true;
}

bool compare_all(int64_t num) {
	return compare(num * 2) & compare(num * 3)
	     & compare(num * 4) & compare(num * 5)
	     & compare(num * 6);
}

int main() {
	int64_t num;
	for(num = 1; !compare_all(num); load_a(++num));
	printf("%" PRId64 "\n", num);
	return 0;
}