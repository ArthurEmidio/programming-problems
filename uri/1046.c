#include <stdio.h>

int main() {
	int start, end;
	scanf("%d %d", &start, &end);
	
	int elapsed;
	if (end < start) {
		elapsed = 24 - start + end;
	} else if (end > start) {
		elapsed = end - start;
	} else {
		elapsed = 24;
	}
    
    printf("O JOGO DUROU %d HORA(S)\n", elapsed);
    
    return 0;
}