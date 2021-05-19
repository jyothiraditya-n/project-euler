#include <inttypes.h>
#include <stdio.h>

uint16_t least_factor(uint64_t n) {
	if(n % 2 == 0) return 2;

	uint16_t i;
	for(i = 3; n % i != 0; i++);

	return i;
}

int main() {
	uint64_t num = 600851475143;
	uint16_t factor = least_factor(num);

	while(factor != num) {
		num /= factor;
		factor = least_factor(num);
	}
	
	printf("%" PRIu16 "\n", factor);
	return 0;
}

