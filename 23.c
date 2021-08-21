/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t intsqrt(int64_t number) {
	int64_t i = 1;
	
	while(i * i <= number) {
		i++;
	}
	
	return i -1;
}

int64_t sum_of_divs(int64_t number) {
	int64_t sqrtnum = intsqrt(number);
	
	int64_t sum = 0;
	
	for(int64_t i = 1; i <= sqrtnum; i++) {
		if(number % i == 0) {
			if(i == number / i) sum += i;
			else sum += i + (number / i);
		}
	}
	
	return sum;
}

int64_t sum_divs[28124];

int main() {
	for(int64_t i = 0; i < 28124; i++) sum_divs[i] = sum_of_divs(i) - i;
	int64_t sum = 0;
	
	for(int64_t i = 0; i < 28124; i++) {
		sum += i;
		
		for(int64_t j = 0; j <= i / 2; j++) {
			if((sum_divs[j] > j) && (sum_divs[i - j] > i - j)) {
				sum -= i;
				break;
			}
		}
	}
	
	printf("%" PRId64 "\n", sum);
}
