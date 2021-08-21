/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int main() {
	int64_t choices[21][21];
	
	for(int64_t i = 20; i > -1; i--) {
		choices[i][20] = 0;
		choices[20][i] = 0;
	}
	
	for(int64_t i = 19; i > -1; i--) {
		for(int64_t j = i; j > -1; j--) {
			choices[i][j] = choices[i + 1][j] + choices[i][j + 1] + 1;
			choices[j][i] = choices[j + 1][i] + choices[j][i + 1] + 1;
		}
	}
	
	printf("%" PRId64 "\n", choices[0][0] + 1);
	return 0;
}
