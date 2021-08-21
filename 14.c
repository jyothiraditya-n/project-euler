#include <inttypes.h>
#include <stdio.h> 

int main() {
	int64_t chain_lengths[1000000];
	int64_t max_length = 1;
	int64_t max_number = 1;
	
	chain_lengths[0] = 1;
	
	for(int64_t i = 2; i < 1000000; i++) {
		int64_t number = i;
		chain_lengths[i - 1] = 0;
		
		while(number >= i) {
			chain_lengths[i - 1]++;
			if(number % 2 == 0) number /= 2;
			else number = (3 * number) + 1;
		}
		
		chain_lengths[i - 1] += chain_lengths[number - 1];
		
		if(chain_lengths[i - 1] > max_length) {
			max_length = chain_lengths[i - 1];
			max_number = i;
		}
	}
	
	printf("%" PRId64 "\n", max_number);
	return 0;
}
