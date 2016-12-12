#include <bits/stdc++.h>

using namespace std;

int n, a, b, c;
int dp[4005];

int solve(int length)
{
    if (length < 0) return INT_MIN;
    if (length == 0) return 0;
    if (dp[length] != -1) return dp[length];
    return dp[length] = 1 + max(max(solve(length - a), solve(length - b)), solve(length - c)); 
}

int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> a >> b >> c;
    cout << max(solve(n), 0) << endl;
    return 0;
}
