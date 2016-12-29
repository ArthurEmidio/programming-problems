#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{    
    int n;
    scanf("%d", &n);
    
    ll v[100005] = {}, dp[100005];
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        v[a]++;
    }
    
    dp[0] = 0, dp[1] = v[1];
    for (int i = 2; i <= 100000; i++) dp[i] = max(dp[i-1], v[i]*i + dp[i-2]);    
    printf("%lld\n", dp[100000]);
    
    return 0;
}
