#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int dp[100005][2];
int n;

int solve(int i, int x)
{
    if (i >= n || x < 0) return 0;
    int &ans = dp[i][x];
    if (ans != -1) return ans;
    
    if (i+1 < n && v[i] >= v[i+1]) {
        if (x == 0) ans = 1;
        else if (v[i+1]-1 > v[i-1]) ans = 1 + solve(i+1, x-1);        
        else if (i+2 < n && v[i+2] > v[i]+1) ans = 2 + solve(i+2, x-1);
        else ans = 2;
    } else {
        ans = 1 + solve(i+1, x);
    }
    
    return ans;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    
    v.assign(n, 0);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (i+1 < n && v[i] >= v[i+1]) ? max(ans, 1 + solve(i+1, 0)) : max(ans, solve(i, 1));       
    }
    printf("%d\n", ans);
    
    return 0;
}
