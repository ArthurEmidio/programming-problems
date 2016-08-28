#include <stdio.h>
#include <stdint.h>
#include <math.h>

int isPrime(uint64_t n) {
	if (n <= 1) return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	
	uint64_t upperBound = sqrt(n);
	for (uint64_t d = 5; d <= upperBound; d += 6) {
		if (n % d == 0 || n % (d+2) == 0) {
			return 0;
		}
	}
	
	return 1;
}

int main() {
	int count = 2;
	uint64_t i = 5;
	while(1) {
		if (isPrime(i)) {
			count++;
			if (count == 10001) break;
		}
		
		i += 2;
		
		if (isPrime(i)) {
			count++;
			if (count == 10001) break;
		}

		i += 4;
	}
	
	printf("%lld\n", i);
	
	return 0;
}