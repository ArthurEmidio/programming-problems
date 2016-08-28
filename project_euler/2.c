#include <stdio.h>
#include <stdint.h>

int main() {
	int prev = 1;
	int curr = 2;
	int temp;
	int64_t sum = 0;
	
	while (prev <= 4000000) {
		sum += (prev % 2 == 0) ? prev : 0;		
		temp = prev;
		prev = curr;
		curr += temp;
	}
	
	printf("%lld\n", sum);
	
	return 0;
}