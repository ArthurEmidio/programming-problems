#include <stdio.h>

int main() {
	int sumSquares = 0;
	int squareOfSum = 0;
	for (int i = 1; i <= 100; i++) {
		sumSquares += i*i;
		squareOfSum += i;
	}
	squareOfSum *= squareOfSum;
	
	printf("%d\n", squareOfSum - sumSquares);
	
	return 0;
}