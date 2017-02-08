#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x)
{
    if (x == 0 || x == 1) return false;
    
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int m;
    for (m = 1; m <= 1000; m++) {
        if (!isPrime(n * m + 1)) break;
    }
    printf("%d\n", m);
    
    return 0;
}