#include <inttypes.h>
#include <stdio.h>

uint32_t number = 1;
uint8_t count = 0;
uint16_t gap = 2;
uint16_t steps = 0;

uint32_t sum = 1;

void next_number() {
	number++;
	steps++;

	if(steps == gap) {
		sum += number;
		count++;
		steps = 0;
	}

	if(count == 4) {
		count = 0;
		gap += 2;
	}

	return;
}

int main() {
	for(; number < 1002001; next_number());

	printf("%" PRIu32 "\n", sum);
	return 0;
}