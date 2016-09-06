#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save(char **wordPointer, const char *str) {
	*wordPointer = malloc(sizeof(char) * strlen(str));
	strcpy(*wordPointer, str);
}

int main() {
	char **words = malloc(sizeof(char*) * 30);
	save(&words[1], "vertebrado");
	save(&words[2], "invertebrado");
	
	save(&words[3], "ave");
	save(&words[4], "mamifero");
	save(&words[5], "inseto");
	save(&words[6], "anelideo");
	
	save(&words[7], "carnivoro");
	save(&words[8], "onivoro");
	save(&words[9], "onivoro");
	save(&words[10], "herbivoro");
	save(&words[11], "hematofago");
	save(&words[12], "herbivoro");
	save(&words[13], "hematofago");
	save(&words[14], "onivoro");
	
	save(&words[15], "aguia");
	save(&words[17], "pomba");
	save(&words[19], "homem");
	save(&words[21], "vaca");
	save(&words[23], "pulga");
	save(&words[25], "lagarta");
	save(&words[27], "sanguessuga");
	save(&words[29], "minhoca");
	
	char w1[20], w2[20], w3[20];
	scanf("%s", w1);
	getchar();
	scanf("%s", w2);
	getchar();
	scanf("%s", w3);
	
	char **ws = malloc(sizeof(char*) * 3);
	ws[0] = w1;
	ws[1] = w2;
	ws[2] = w3;
	
	int currIndex = 1;
	for (int i = 0; i < 3; i++) {
		if (strcmp(words[currIndex], ws[i]) == 0) {
			currIndex = currIndex*2 + 1;
		} else {
			currIndex = (currIndex+1)*2 + 1;
		}
	}
	
	printf("%s\n", words[currIndex]);
		
	return 0;
}