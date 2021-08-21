/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>
	
uint8_t a[1000], b[1000], c[1000];

void add(uint8_t *a, uint8_t *b, uint8_t *c) {
	for(int16_t i = 0; i < 1000; i++) {
		c[i] = 0;
	}

	for(int16_t i = 0; i < 999; i++) {
		c[i + 1] = (a[i] + b[i] + c[i]) / 10;
		c[i] = (a[i] + b[i] + c[i]) % 10;
	}

	return;
}

int main() {
	uint8_t *two_back = &a[0];
	uint8_t *one_back = &b[0];
	uint8_t *current = &c[0];

	uint32_t index;

	
	for(uint16_t i = 0; i < 1000; i++) {
		two_back[i] = 0;
		one_back[i] = 0;
		current[i] = 0;
	}

	two_back[0] = 1;
	one_back[0] = 1;
	current[0] = 2;

	uint8_t *temp;

	for(index = 3; !current[999]; index++) {
		temp = two_back;

		two_back = one_back;
		one_back = current;

		current = temp;
		add(one_back, two_back, current);
	}
	
	printf("%" PRIu32 "\n", index);
	return 0;
}