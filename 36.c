#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

bool ispalindrome(uint32_t n) {
	char string[8];
	sprintf(string, "%" PRIu32, n);

	uint8_t i = 0;
	size_t j = strlen(string) - 1;

	while(i < j) {
		if(string[i] != string[j]) return false;

		i++;
		j--;
	}

	if(i < j) return false;
	
	bool digits[32];

	for(i = 0; n >= 2; i++) {
		digits[i] = n & 1 ? true : false;
		n >>= 1;
	}

	digits[i] = n ? true : false;
	j = i;
	i = 0;

	while(i < j) {
		if(digits[i] != digits[j]) return false;

		i++;
		j--;
	}

	if(i >= j) return true;
	return false;

}

int main() {
	uint32_t sum = 0;
	
	for(uint32_t i = 0; i < 1000000; i++) {
		if(ispalindrome(i)) sum += i;
	}
	
	printf("%" PRIu32 "\n", sum);
	return 0;
}
