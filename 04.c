#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

const char *title = "Problem 4: Largest palindrome product";

const char *desc = "A palindromic number reads the same both ways. The largest "
"palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.";

const char *question = "Find the largest palindrome made from the product of "
"two 3-digit numbers.";

int main() {
	printf("%s\n\n", title);
	printf("%s\n\n", desc);
	printf("%s\n\n", question);
	
	uint32_t product = 0;
	char prodstr[8] = {0};
	
	uint32_t highest = 0;
	
	for(uint16_t i = 999; i > 99; i--)
		for(uint16_t j = 999; j >= i; j--)
	{
		product = i * j;
		
		if(product <= highest) continue;
		
		sprintf(prodstr, "%" PRIu32, product);
		
		uint8_t start = 0;
		size_t end = strlen(prodstr) - 1;
		
		while(end > start) {
			if(prodstr[start] != prodstr[end]) break;
			
			start++;
			end--;
		}
		
		if(start >= end) highest = product;
	}
	
	printf("Solution: %" PRIu32 "\n", highest);
	return 0;
}
