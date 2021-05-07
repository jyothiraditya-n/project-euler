#include <inttypes.h>
#include <stdio.h>

const char *title = "Problem 3: Largest prime factor";

const char *desc = "The prime factors of 13195 are 5, 7, 13 and 29.";

const char *question = "What is the largest prime factor of the number "
"600851475143?";

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	uint64_t number = 600851475143;

	uint32_t i = 2;
	
	while(i < number) {
		if(number % i == 0) {
			number /= i;

			i = 2;
			continue;
		}
		
		i++;
	}
	
	printf("Solution: %" PRIu32 "\n", i);
	return 0;
}
