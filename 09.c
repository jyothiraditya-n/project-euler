#include <inttypes.h>
#include <stdio.h>

const char *title = "Problem 9: Special Pythagorean triplet";

const char *desc = "A Pythagorean triplet is a set of three natural numbers, "
"a < b < c, for which\n\n"

"(a ^ 2) + (b ^ 2) = c ^ 2\n\n"

"For example, (3 ^ 2) + (4 ^ 2) = 9 + 16 = 25 = (5 ^ 2).";

const char *question = "There exists exactly one Pythagorean triplet for which "
"a + b + c = 1000.\n\n"

"Find the product abc.";

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	uint16_t a = 998;
	uint16_t b = 1;
	uint16_t c = 1;

	while((a * a) + (b * b) != (c * c)) {
		b++;
		c--;

		if(b > c) {
			a--;
			b = 1;
			c = 999 - a;
		}
	}

	uint32_t product = a * b * c;

	printf("Solution: %" PRIu32 "\n", product);
	return 0;
}
