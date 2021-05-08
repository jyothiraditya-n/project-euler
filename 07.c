#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const char *title = "Problem 7: 10001st prime";

const char *desc = "By listing the first six prime numbers: 2, 3, 5, 7, 11, "
"and 13, we can see that the 6th prime is 13.";

const char *question = "What is the 10001st prime number?";

typedef struct prime_s {
	struct prime_s *next;
	uint32_t value;

} prime_t;

prime_t start;
prime_t *last;

void find_prime();
bool isprime(uint32_t number);

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	start.next = 0;
	start.value = 2;
	
	last = &start;

	for(uint16_t i = 1; i < 10001; i++) {
		find_prime();
	}
	
	printf("Solution: %" PRIu32 "\n", last -> value);
	return 0;
}

void find_prime() {
	uint32_t number = last -> value + 2;
	if(number == 4) number = 3;

	while(!isprime(number)) {
		number += 2;
	}

	prime_t *new = malloc(sizeof(prime_t));
	new -> next = 0;
	new -> value = number;

	last -> next = new;
	last = new;
}

bool isprime(uint32_t number) {
	prime_t *current = &start;

	while(current) {
		if(!(number % current -> value)) return false;

		current = current -> next;
	}

	return true;
}