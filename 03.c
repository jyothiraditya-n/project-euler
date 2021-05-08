#include <inttypes.h>
#include <stdio.h>

const char *title = "Problem 3: Largest prime factor";

const char *desc = "The prime factors of 13195 are 5, 7, 13 and 29.";

const char *question = "What is the largest prime factor of the number "
"600851475143?";

uint16_t smallest_factor(uint64_t number);

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	uint64_t number = 600851475143;

	uint16_t factor = smallest_factor(number);
	
	while(factor != number) {
		number /= factor;
		factor = smallest_factor(number);
	}
	
	printf("Solution: %" PRIu16 "\n", factor);
	return 0;
}

uint16_t smallest_factor(uint64_t number) {
	if(!(number % 2)) return 2;

	uint16_t factor = 3;

	while(number % factor) {
		factor += 2;
	}

	return factor;
}