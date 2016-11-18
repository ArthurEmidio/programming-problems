#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

ll dp[105][105];

ll solve(int n, int k)
{
    if (k == 1) return 1;
    if (dp[n][k] != -1) return dp[n][k];
    
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + solve(n - i, k - 1)) % 1000000;
    }
    
    return dp[n][k] = (ans % 1000000);
}

int main()
{
    for (;;) {
        int n, k;
        cin >> n >> k;
        if (!n && !k) break;
        
        memset(dp, -1, sizeof dp);
        printf("%lld\n", solve(n, k) % 1000000);
    }
    
    return 0;
}
