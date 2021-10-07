/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

int64_t buffer[1024];

bool inbuf(int64_t val) {
	for(int64_t i = 0; buffer[i]; i++)
		if(buffer[i] == val) return true;

	return false;
}

int64_t cycle_len(int64_t d) {
	for(int64_t i = 1; i < 1024; i++) buffer[i] = 0;
	buffer[0] = 10;

	int64_t val = 10, count = 1;

	while(true) {
		if(val > d) val %= d;
		val *= 10;

		if(inbuf(val)) break;
		else if(!val) break;
		else buffer[count++] = val;
	}

	return count;
}

int main() {
	int64_t d = 0, max = 0;

	for(int64_t i = 2; i < 1000; i++) {
		int64_t len = cycle_len(i);
		if(len > max) { max = len; d = i; }
	}

	printf("%" PRId64 "\n", d);
}