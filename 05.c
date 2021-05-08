#include <inttypes.h>
#include <stdio.h> 

const char *title = "Problem 5: Smallest multiple";

const char *desc = "2520 is the smallest number that can be divided by each of "
"the numbers from 1 to 10 without any remainder.";

const char *question = "What is the smallest positive number that is evenly "
"divisible by all of the numbers from 1 to 20?";

uint8_t missing_factor(uint32_t number, uint8_t divisor);

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	uint32_t number = 1;
	
	for(uint8_t i = 2; i <= 20; i++) {
		number *= number % i ? missing_factor(number, i) : 1;
	}
	
	printf("Solution: %" PRIu32 "\n", number);
	return 0;
}

uint8_t missing_factor(uint32_t number, uint8_t divisor) {
	uint8_t factor = 2;

	while((number * factor) % divisor) {
		factor++;
	}

	return factor;
}