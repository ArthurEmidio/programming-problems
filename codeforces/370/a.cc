#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    
    ll prev;
    scanf("%lld", &prev);
    
    ll curr;
    for (int i = 1; i < n; i++) {
        scanf("%lld", &curr);
        printf("%lld ", prev + curr);
        prev = curr;
    }
    printf("%lld\n", curr);
        
    return 0;
}
