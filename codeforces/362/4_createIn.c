#include <stdio.h>

int main()
{
    FILE *fp = fopen("in.txt", "w");
    
    fprintf(fp, "100000\n");
    for (int i = 1; i <= 100000; i++) {
        fprintf(fp, "%d ", i);
    }
    
    fclose(fp);
    
}