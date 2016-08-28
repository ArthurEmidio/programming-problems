#include <stdio.h>
#include <stdint.h>

int isPrime(int64_t n) {
	if (n <= 1) return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	
	int64_t upper = n/2;	
	for (int64_t i = 5; i < upper; i += 6) {
		if (n % i == 0 || n % (i+2) == 0) return 0;
	}
	
	return 1;
}

int main() {
	int64_t num = 600851475143;
	
	int64_t result = num;
	int64_t upper = num/2;
	for (int64_t i = 2; i < num/2; i++) {
		if (num % i == 0 && isPrime(num/i)) {
			result = num/i;
			break;
		}
	}
	
	printf("%lld\n", result);
	
	return 0;
}