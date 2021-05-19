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

	if(i >= j) return true;
	return false;
}

int main() {
	uint32_t product = 0;
	uint32_t highest = 0;
	
	for(uint16_t i = 999; i > 99; i--)
		for(uint16_t j = 999; j >= i; j--)
	{
		product = i * j;
		
		if(product <= highest) continue;
		if(ispalindrome(product)) highest = product;
	}
	
	printf("%" PRIu32 "\n", highest);
	return 0;
}
