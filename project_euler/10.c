#include <stdio.h>
#include <stdint.h>
#include <math.h>

int isPrime(int n) {
	if (n <= 1) return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	
	for (int i = 5; i <= sqrt(n); i += 6) {
		if (n % i == 0 || n % (i+2) == 0) {
			return 0;
		}
	}
	
	return 1;
}

int main() {
	int64_t sum = 2 + 3;
	
	for (int i = 5; i < 2000000; i += 6) {
		sum += isPrime(i) ? i : 0;
		sum += isPrime(i+2) ? i+2 : 0;
	}
	
	printf("%lld\n", sum);
	
	return 0;
}