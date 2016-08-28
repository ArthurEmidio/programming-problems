#include <stdio.h>

int main() {
	FILE *fp = fopen("p11_numbers.txt", "r");
	int currNum;
	int i = 0, j = 0;
	
	int mat[20][20];
	int greatestProd = 0;
	
	while (fscanf(fp, "%d", &currNum) != EOF) {
		mat[i][j] = currNum;
		
		if (j == 19) {
			j = 0;
			i++;
		} else {
			j++;
		}
	}
	fclose(fp);	
	
	int prod;
for (int i = 0; i < 20; i++) {
for (int j = 0; j < 20; j++) {
	if (j <= 16) {
		prod = mat[i][j]*mat[i][j+1]*mat[i][j+2]*mat[i][j+3];
		if (prod > greatestProd) greatestProd = prod;
		if (i <= 16) {
			prod = mat[i][j]*mat[i+1][j+1]*mat[i+2][j+2]* mat[i+3][j+3];
			if (prod > greatestProd) greatestProd = prod;
		}
	}
			
			if (i <= 16) {
				prod = mat[i][j]*mat[i+1][j]*mat[i+2][j]*mat[i+3][j];
				if (prod > greatestProd) greatestProd = prod;
				if (j >= 3) {
					prod = mat[i][j]*mat[i+1][j-1]*mat[i+2][j-2]*mat[i+3][j-3];
					if (prod > greatestProd) greatestProd = prod;
				}
			}
}
}	
	
	printf("%d\n", greatestProd);

	return 0;
}