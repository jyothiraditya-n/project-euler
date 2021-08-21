#include <inttypes.h>
#include <stdio.h> 

int64_t sum_divs(int64_t number) {
	int64_t sum = 0;
	
	for(int64_t i = 1; i < number; i++) {
		if(number % i == 0) sum += i;
	}
	
	return sum;
}

int main() {
	int64_t sum = 0;
	
	for(int64_t i = 1; i < 10000; i++) {
		if((sum_divs(sum_divs(i)) == i) && (sum_divs(i) != i)) sum += i;
	}
	
	printf("%" PRId64 "\n", sum);
	return 0;
}
