#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll dp[1005]; // dp[i] = min number of contestants s.t. the winner has won i matches
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i < 1005; i++) dp[i] = dp[i-1] + dp[i-2];
        
    ll n;
    cin >> n;
    int ans = 1;
    while (dp[ans] <= n) ans++;    
    cout << ans-1 << endl;
    
    return 0;
}
