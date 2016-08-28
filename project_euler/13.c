#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main() {
	FILE *fp = fopen("p13_numbers.txt", "r");
	
	char n;
	int i = 0, j = 0;
	int digitCount = 9;
	uint64_t currNumber = 0;
	uint64_t numbers[100][5];
	
	while (fscanf(fp, "%c", &n) != EOF) {
		if (n == '\n') continue;
				
		currNumber += ((int64_t)(n-48)) * pow(10, digitCount);
		digitCount--;
		
		if (digitCount == -1) {
			numbers[i][j] = currNumber;		
			currNumber = 0;
			digitCount = 9;
			j++;
			if (j == 5) {
				j = 0;
				i++;
			}
		}	
	}
	
	int64_t rem = 0;
	int64_t sum;
	for (int j = 4; j >= 0; j--) {
		sum = rem;
		for (int i = 0; i < 100; i++) {
			sum += numbers[i][j];
		}
		rem = sum/pow(10, 10);
	}
	
	printf("%lld\n", sum);
		
	return 0;
}