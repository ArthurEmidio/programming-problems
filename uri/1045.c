#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    if (*(float*)a > *(float*)b) return -1;
    if (*(float*)a < *(float*)b) return 1;
    return 0;
}

int main() {
	float sides[3];
    scanf("%f %f %f", &sides[0], &sides[1], &sides[2]);
    qsort(sides, 3, sizeof(float), compare);
	
    float a = sides[0];
    float b = sides[1];
    float c = sides[2];
        
    if (a >= b + c) {
        printf("NAO FORMA TRIANGULO\n");
    } else {
        if (a*a == b*b + c*c) {
            printf("TRIANGULO RETANGULO\n");
        } else if (a*a > b*b + c*c) {
            printf("TRIANGULO OBTUSANGULO\n");
        } else if (a*a < b*b + c*c) {
            printf("TRIANGULO ACUTANGULO\n");
        }
        
        if (a == b && b == c) {
            printf("TRIANGULO EQUILATERO\n");
        } else if (a == b || b == c || a == c) {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    
    return 0;
}