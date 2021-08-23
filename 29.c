#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct { int64_t prime; int64_t power; } factor_t;

typedef struct _node_s {
	struct _node_s *next;
	factor_t divs[31];
	
} node_t;

node_t first;

int64_t getpdiv(int64_t a) {
	for(int64_t div = 2; div <= a; div++)
		if(a % div == 0) return div;

	return 1;
}

node_t *raise(int64_t a, int64_t b) {
	node_t *ret = calloc(1, sizeof(node_t));

	while(a > 1) {
		int64_t div = getpdiv(a);
		a /= div;

		int64_t i;
		for(i = 0; ret -> divs[i].prime; i++)
			if(ret -> divs[i].prime == div) break;

		ret -> divs[i].prime = div;
		ret -> divs[i].power++;
	}

	for(int64_t i = 0; i < 31; i++) ret -> divs[i].power *= b;
	return ret;
}

bool nodes_are_equal(node_t *a, node_t *b) {
	for(int64_t i = 0; i < 31; i++) {
		if(a -> divs[i].prime != b -> divs[i].prime) return false;
		if(a -> divs[i].power != b -> divs[i].power) return false;
	}

	return true;
}

int main() {
	for(int64_t a = 2; a <= 100; a++)
		for(int64_t b = 2; b <= 100; b++)
	{
		node_t *result = raise(a, b);
		node_t *node = &first, *last = &first;

		while(node) {
			if(nodes_are_equal(result, node)) break;
			last = node; node = node -> next;
		}

		if(!node) {
			last -> next = result;
		}
	}

	int64_t count = -1;
	node_t *node = &first;

	while(node) { count++; node = node -> next; }
	printf("%" PRId64 "\n", count);
	return 0;
}