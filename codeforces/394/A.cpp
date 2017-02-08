#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%s\n", abs(a - b) <= 1 && (a || b) ? "YES" : "NO");

    return 0;
}
