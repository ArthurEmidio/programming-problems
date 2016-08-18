#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPalindrome(int n) {
	char str[32];
	int length = sprintf(str, "%d", abs(n));
	
	for (int i = 0; i < length/2; i++) {
		int x = (int)(n/pow(10, i)) % 10;
		int y = (int)(n/pow(10, length-i-1)) % 10;
		if (x != y) return 0;
	}
	
	return 1;
}

int main() {
	
	int i, j;
	int max = 0;

	for (i = 999; i >= 100; i--) {
		for (j = 999; j >= 100; j--) {
			int n = i*j;
			if (isPalindrome(n) && n > max) {
				max = n;
			}
		}
	}

	printf("%d\n", max);
	
	return 0;
}