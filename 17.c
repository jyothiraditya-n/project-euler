#include <inttypes.h>
#include <stdio.h>

int main() {
	int64_t sum = 0;
	
	for(int64_t i = 1; i < 1000; i++) {
		int64_t units = i % 10;
		int64_t tens = (i / 10) % 10;
		int64_t hundreds = i / 100;
		
		if(hundreds == 1) sum += 3 + 7;
		else if(hundreds == 2) sum += 3 + 7;
		else if(hundreds == 3) sum += 5 + 7;
		else if(hundreds == 4) sum += 4 + 7;
		else if(hundreds == 5) sum += 4 + 7;
		else if(hundreds == 6) sum += 3 + 7;
		else if(hundreds == 7) sum += 5 + 7;
		else if(hundreds == 8) sum += 5 + 7;
		else if(hundreds == 9) sum += 4 + 7;
		
		if((hundreds != 0) && ((tens != 0) || (units != 0))) {
			sum += 3;
		}
		
		if(tens == 1) {
			if(units == 0) sum += 3;
			else if(units == 1) sum += 6;
			else if(units == 2) sum += 6;
			else if(units == 3) sum += 8;
			else if(units == 4) sum += 8;
			else if(units == 5) sum += 7;
			else if(units == 6) sum += 7;
			else if(units == 7) sum += 9;
			else if(units == 8) sum += 8;
			else if(units == 9) sum += 8;
			
			continue;
		}
		
		else if(tens == 2) sum += 6;
		else if(tens == 3) sum += 6;
		else if(tens == 4) sum += 5;
		else if(tens == 5) sum += 5;
		else if(tens == 6) sum += 5;
		else if(tens == 7) sum += 7;
		else if(tens == 8) sum += 6;
		else if(tens == 9) sum += 6;
		
		if(units == 1) sum += 3;
		else if(units == 2) sum += 3;
		else if(units == 3) sum += 5;
		else if(units == 4) sum += 4;
		else if(units == 5) sum += 4;
		else if(units == 6) sum += 3;
		else if(units == 7) sum += 5;
		else if(units == 8) sum += 5;
		else if(units == 9) sum += 4;
	}
	
	sum += 11;
	
	printf("%" PRId64 "\n", sum);
	return 0;
}
