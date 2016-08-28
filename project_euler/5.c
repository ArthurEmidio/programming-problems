#include <stdio.h>
#include <stdint.h>

int main() {
	uint64_t n = 0;
	int found = 0;
	while (!found) {
		n += 20;
		
		found = 1;
		for (int i = 1; i <= 20; i++) {
			if (n % i != 0) {
				found = 0;
				break;
			}
		}		
	}
	
	printf("%lld\n", n);
	
	return 0;
}