#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

const char *title = "Problem 10: Summation of primes";

const char *desc = "The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.";

const char *question = "Find the sum of all the primes below two million.";

bool filtered[2000000];

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	for(uint32_t i = 2; i < 2000000; i++) {
		filtered[i] = true;
	}
	
	for(uint32_t i = 2; i < 2000000;i++) {
		uint32_t index = i * 2;

		if(!filtered[i]) continue;
		
		while(index < 2000000) {
			filtered[index] = false;

			index += i;
		}
	}
	
	uint64_t sum = 0;

	for(uint32_t i = 2; i < 2000000; i++) {
		sum += filtered[i] ? i : 0;
	}
	
	printf("Solution: %" PRIu64 "\n", sum);
	return 0;
}