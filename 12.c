#include <inttypes.h>
#include <stdio.h>

const char *title = "Problem 12: Highly divisible triangular number";

const char *desc = "The sequence of triangle numbers is generated by adding "
"the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 "
"+ 6 + 7 = 28. The first ten terms would be:\n\n"

"1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...\n\n"

"We can see that 28 is the first triangle number to have over five divisors.";

const char *question = "What is the value of the first triangle number to have "
"over five hundred divisors?";

uint16_t num_divs(uint32_t);

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	uint16_t i = 1;
	uint32_t number = 0;
	
	while(num_divs(number) < 500) {
		number += i;

		i++;
	}
	
	printf("Solution: %" PRIu32 "\n", number);
	return 0;
}

uint32_t int_sqrt(uint32_t);

uint16_t num_divs(uint32_t number) {
	uint16_t total = 0;

	uint32_t limit = int_sqrt(number);

	for(uint32_t i = 1; i <= limit; i++) if(number % i == 0) {
		if(i == number / i) total++;
		else total += 2;
	}

	return total;
}

uint32_t int_sqrt(uint32_t number) {
	if(!number) return 0;

	uint32_t i = 1;
	while(i * i <= number) i++;
	
	return i -1;
}