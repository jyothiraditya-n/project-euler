#include <inttypes.h>
#include <stdio.h>

const char *title = "Problem 25: 1000-digit Fibonacci number";

const char *desc = "The Fibonacci sequence is defined by the recurrence "
"relation:\n\n"

"F(n) = F(n−1) + F(n−2), where F(1) = 1 and F(2) = 1.\n\n"

"Hence the first 12 terms will be:\n\n"

"1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...\n\n"

"The 12th term, F12, is the first term to contain three digits.";

const char *question = "What is the index of the first term in the Fibonacci "
"sequence to contain 1000 digits?";
	
uint8_t a[1000], b[1000], c[1000];

void add(uint8_t *a, uint8_t *b, uint8_t *c);

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);

	uint8_t *two_back = &a[0];
	uint8_t *one_back = &b[0];
	uint8_t *current = &c[0];

	for(uint16_t i = 0; i < 1000; i++) {
		two_back[i] = 0;
		one_back[i] = 0;
		current[i] = 0;
	}

	two_back[0] = 1;
	one_back[0] = 1;
	current[0] = 2;

	uint32_t index = 3;
	
	while(!current[999]) {
		uint8_t *temp = two_back;

		two_back = one_back;
		one_back = current;

		current = temp;
		add(one_back, two_back, current);

		index++;
	}
	
	printf("Solution: %" PRIu32 "\n", index);
	return 0;
}

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