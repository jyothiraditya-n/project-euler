/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>

int64_t tris[1024];

int64_t int_sqrt(int64_t n) {
	int64_t sqrt = 1, comp = n;
	int64_t sqrt_1 = 0, sqrt_2 = 0;

	while(sqrt != sqrt_2) {
		sqrt_2 = sqrt_1;
		sqrt_1 = sqrt;

		sqrt = (sqrt + comp) / 2;
		comp = n / sqrt;
	}

	return sqrt;
}

int64_t get_hyp(int64_t a, int64_t b) {
	int64_t hyp = int_sqrt(a * a + b * b);
	if(hyp * hyp != a * a + b * b) return 0;
	else return hyp;
}

int main() {
	for(int64_t a = 1; a < 1000; a++)
		for(int64_t b = a; b < 1000; b++)
	{
		int64_t hyp = get_hyp(a, b);

		if(a + b + hyp > 1000) break;
		if(hyp) tris[a + b + hyp]++;
	}

	int64_t max = 0, max_i = 0;
	for(int64_t i = 1; i <= 1000; i++)
		if(tris[i] > max) { max = tris[i]; max_i = i; }

	printf("%" PRId64 "\n", max_i);
	return 0;
}