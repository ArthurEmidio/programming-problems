#include <stdio.h>
#include <stdint.h>

int collatz(uint64_t n) {
	if (n == 1) return 1;

	if (n % 2 == 0) {
		return 1 + collatz(n/2);
	} else {
		return 1 + collatz(3*n + 1);
	}
}

int main() {
	int greatest = 0;
	int startingN;
	
	for (int i = 2; i < 1000000; i++) {
		int n = collatz(i);
		if (n > greatest) {
			greatest = n;
			startingN = i;
		}
	}

	printf("%d\n", startingN);
	
	// printf("%d\n", collatz(13));
	
	return 0;
}