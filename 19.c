#include <inttypes.h>
#include <stdio.h> 

int main() {
	int64_t day = 1;
	int64_t date = 1;
	int64_t month = 1;
	int64_t year = 1900;
	
	int64_t total = 0;
	
	while(year < 2001) {
		date++;
		
		if((month == 9) || (month == 4) || (month == 6) || (month == 11)) {
			if(date > 30) {
				date = 1;
				month++;
			}
		}
		
		else if(month == 2) {
			if(year % 4 == 0) {
				if((year % 100 != 0) || (year % 400 == 0)) {
					if(date > 29) {
						date = 1;
						month++;
					}
				}
				
				else if(date > 28) {
					date = 1;
					month++;
				}
			}
			
			else if(date > 28) {
				date = 1;
				month++;
			}
		}
		
		else if(month == 12) {
			if(date > 31) {
				date = 1;
				month = 1;
				year++;
			}
		}
		
		else if(date > 31) {
			date = 1;
			month++;
		}
		
		day++;
		if(day > 7) day = 1;
		if((day == 7) && (date == 1) && (year != 1900)) total++;
	}
	
	printf("%" PRId64 "\n", total);
	return 0;
}
