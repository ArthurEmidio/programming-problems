#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll dp[105][2];
int n, k, d;

ll solve(int i, bool used)
{   
    if (i < 0) return 0;
    if (!i) return used;
    
    ll &ans = dp[i][used];
    if (ans != -1) return ans;
    
    ans = 0;
    for (int x = 1; x <= k; x++) ans = (ans + solve(i - x, used ? used : (x >= d))) % MOD;
    
    return ans;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d %d %d", &n, &k, &d);
    printf("%lld\n", solve(n, false));
    return 0;
}
