#include <stdio.h>

int main() {
	float salary;
	scanf("%f", &salary);
    float initialSalary = salary;
	
	int increase;
	if (salary <= 400.00) {
		increase = 15;
		salary *= 1.15;
	} else if (salary <= 800.00) {
		increase = 12;
		salary *= 1.12;
	} else if (salary <= 1200.00) {
		increase = 10;
		salary *= 1.10;
	} else if (salary <= 2000.00) {
		increase = 7;
		salary *= 1.07;
	} else {
		increase = 4;
		salary *= 1.04;
	}
	
	printf("Novo salario: %.2f\n", salary);
	printf("Reajuste ganho: %.2f\n", initialSalary * increase/100);
	printf("Em percentual: %d %c\n", increase, '%');
	
	return 0;
}