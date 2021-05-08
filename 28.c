#include <inttypes.h>
#include <stdio.h>

const char *title = "Problem 28: Number spiral diagonals";

const char *desc = "Starting with the number 1 and moving to the right in a "
"clockwise direction a 5 by 5 spiral is formed as follows:\n\n"

"21 22 23 24 25\n"
"20  7  8  9 10\n"
"19  6  1  2 11\n"
"18  5  4  3 12\n"
"17 16 15 14 13\n\n"

"It can be verified that the sum of the numbers on the diagonals is 101.";

const char *question = "What is the sum of the numbers on the diagonals in a "
"1001 by 1001 spiral formed in the same way?";

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);

	uint32_t number = 1;
	uint32_t sum = 1;

	uint8_t count = 0;
	uint16_t gap = 2;
	uint16_t steps = 0;

	while(number < 1002001) {
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
	}

	printf("Solution: %" PRIu32 "\n", sum);
}