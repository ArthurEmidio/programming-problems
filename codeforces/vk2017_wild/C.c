#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int q1 = (n % 2 == 0) ? n/2 : (n/2 - 1);
    if (n % 2 != 0) printf("7");
    for (int i = 0; i < q1; i++) printf("1");
    printf("\n");
    return 0;
}
