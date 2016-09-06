#include <stdio.h>

int main() {
	int startH, startM, endH, endM;
	scanf("%d %d %d %d", &startH, &startM, &endH, &endM);
	
	int elapsedH, elapsedM;
	if (endH < startH) {
		elapsedH = 24 - startH + endH;
	} else if (endH > startH) {
		elapsedH = endH - startH;
	} else {
		elapsedH = 24;
	}
    
	if (endM < startM) {
		elapsedH--;
		elapsedM = 60 - (startM - endM);
	} else {
		elapsedM = endM - startM;
	}
	
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", elapsedH, elapsedM);
    
    return 0;
}
