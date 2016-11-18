#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int dp[55][55];

int solve(int left, int right, const vector<int> &A)
{
    if (left + 1 == right) return 0;
    if (dp[left][right] != -1) return dp[left][right];
    
    int ans = numeric_limits<int>::max();
    for (int i = left+1; i < right; i++) {
        ans = min(solve(left, i, A) + solve(i, right, A), ans);
    }
    
    return dp[left][right] = ans + (A[right] - A[left]);
}

int main()
{
    for (;;) {
        int l;
        cin >> l;
        if (!l) break;
        
        memset(dp, -1, sizeof dp);
        
        int n;
        cin >> n;
        vector<int> cuts(n+2);
        cuts[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> cuts[i];
        }
        cuts[n+1] = l;
        
        printf("The minimum cutting is %d.\n", solve(0, n+1, cuts));
    }
    
    return 0;
}
