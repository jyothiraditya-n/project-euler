#include <inttypes.h>
#include <stdio.h> 

const char *title = "Problem 6: Sum square difference";

const char *desc = "The sum of the squares of the first ten natural numbers "
"is:\n\n"

"(1 ^ 2) + (2 ^ 2) + ... + (10 ^ 2) = 385\n\n"

"The square of the sum of the first ten natural numbers is:\n\n"

"(1 + 2 + ... + 10) ^ 2 = 55 ^ 2 = 3025\n\n"

"Hence the difference between the sum of the squares of the first ten natural "
"numbers and the square of the sum is 3025 - 385 = 2640.";

const char *question = "Find the difference between the sum of the squares of "
"the first one hundred natural numbers and the square of the sum.";

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	uint32_t sum_of_squares = 0;
	uint32_t square_of_sums = 0;
	
	for(uint8_t i = 1; i <= 100; i++) {
		sum_of_squares += i * i;
		square_of_sums += i;
	}
	
	square_of_sums *= square_of_sums;
	
	printf("Solution: %" PRIu32 "\n", square_of_sums - sum_of_squares);
	return 0;
}
