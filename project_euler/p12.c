#include <stdio.h>
#include <math.h>

int hasMoreThan(int n, int divisors) {
	int upperBound = sqrt(n);
	
	int count = 2;
	for (int i = 2; i < upperBound; i++) {
		int rem = n % i;
		if (rem == 0) {
			count++;
			if (n/i > i) count++;
}
	}
	
	return count > divisors;
}

int main() {
	
	int found = 0;
	int n = 1;
	int i = 1;
	while (!found) {
		if (hasMoreThan(n, 500)) {
			found = 1;
		} else {
			i++;
			n += i;
		}
	}

printf("%d\n", n);	

	return 0;
}
