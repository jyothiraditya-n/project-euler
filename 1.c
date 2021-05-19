#include <inttypes.h>
#include <stdio.h>

int main() {
	uint64_t sum = 0;

	for(uint16_t i = 3; i < 1000; i += 3) {
		if(i % 5 != 0) sum += i;
	}

	for(uint16_t i = 5; i < 1000; i += 5) {
		sum += i;
	}
	
	printf("%" PRIu64 "\n", sum);
	return 0;
}
