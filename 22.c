/* Jyothiraditya Nellakra's Solutions to Project Euler Questions */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry_s {
	struct entry_s *next;
	char *name;
} entry_t;

int main() {
	FILE *file = fopen("22_names.txt", "r");
	if(!file) { fprintf(stderr, "error opening 22_names.txt.\n"); exit(1); }
	char *buffer = malloc(4096); buffer[0] = 0;
	
	entry_t first_entry;
	first_entry.next = 0;
	first_entry.name = "";
	
	while(fscanf(file, "%s", buffer) != EOF) {
		entry_t *current_entry = &first_entry;
		
		while(1) {
			if(current_entry -> next == 0) {
				entry_t *new_entry = malloc(sizeof(entry_t));
				new_entry -> next = 0;
				new_entry -> name = buffer;
				
				current_entry -> next = new_entry;
				goto next_name;
			}
			
			else {
				entry_t *previous_entry = current_entry;
				
				for(size_t i = 0; i < strlen(buffer); i++) {
					if(strlen(current_entry -> next -> name) > i) {
						if(current_entry -> next -> name[i] > buffer[i]) break;
						else if(current_entry -> next -> name[i] == buffer[i]) continue;
						
					}
					
					current_entry = current_entry -> next;
					break;
				}
				
				if(previous_entry == current_entry) break;
			}
		}
		
		entry_t *new_entry = malloc(sizeof(entry_t));
		new_entry -> next = current_entry -> next;
		new_entry -> name = buffer;
		
		current_entry -> next = new_entry;
		goto next_name;
	
	next_name:
		buffer = malloc(4096); buffer[0] = 0;
	}
	
	entry_t *current_entry = &first_entry;
	int64_t index = 0;
	int64_t sum = 0;
	
	while(current_entry -> next != 0) {
		index++;
		current_entry = current_entry -> next;
		
		int64_t value = 0;
		
		for(size_t i = 0; i < strlen(current_entry -> name); i++) {
			value += (current_entry -> name[i] - 'A') + 1;
		}
		
		sum += value * index;
	}
	
	printf("%" PRId64 "\n", sum);
}
