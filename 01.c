#include <inttypes.h>
#include <stdio.h>

const char *title = "Problem 1: Multiples of 3 and 5";

const char *desc = "If we list all the natural numbers below 10 that are "
"multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.";

const char *question = "Find the sum of all the multiples of 3 or 5 below "
"1000.";

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	uint32_t sum = 0;

	for(uint16_t i = 3; i < 1000; i += 3) {
		sum += i % 5 ? i : 0;
	}

	for(uint16_t i = 5; i < 1000; i += 5) {
		sum += i;
	}
	
	printf("Solution: %" PRIu32 "\n", sum);
	return 0;
}
