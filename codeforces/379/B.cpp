#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    
    long long form256 = min(min(k2, k5), k6);
    k2 -= form256;
    k5 -= form256;
    k6 -= form256;
    
    long long form32 = min(k3, k2);
    
    printf("%lld\n", 32*form32 + 256*form256);
    
    return 0;
}