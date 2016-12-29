#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> edges;

int dp[200005][3];
set<int> t;

int solve(int v, int i)
{
    if (i == 0) return 1;
    if 
    
    solve[v][i] = 0;
    
    int ans = 0;
    for (int nb : edges[v]) {
        solve(nb, 0);
        solve(nb, 1);
        solve(nb, 2);
        
        solve(nb, min(2, edges[nb].size() - 1));
    }
    
    solve[v][i] = max()
    
    
    
    
    
    
    int &ans = dp[v][i];
    if (ans != -1) return ans;
    
    if (i == 0) {
        if (edges[v].size() == 1) return ans = true;
        else return ans = false;
    }
    
    int cnt = 0;
    for (int nb : edges[v]) {
        if (solve(nb, i-1)) {
            cnt++;
        }
    }
    
    ans = (cnt >= i || solve(v, i-1));
    if (ans) t.insert(v);
    
    for (int nb : edges[v]) solve(nb, i);
    
    return ans;
}

int main()
{
    memset(dp, -1, sizeof dp);
    
    ll n, x, y;
    scanf("%lld %lld %lld", &n, &x, &y);
    
    edges.assign(n, vector<int>());
    int maxDeg = 0;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
        
        maxDeg = max(maxDeg, (int)edges[u-1].size());
        maxDeg = max(maxDeg, (int)edges[v-1].size());
    }
    
    ll ans;
    if (x >= y) {
        ans = (maxDeg == n-1) ? (x + y*(n-2)) : y*(n-1);
    } else {
        int root = 0;
        for (int i = 0; i < n; i++) {
            if (edges[i].size() == 1) {
                root = i;
                break;
            }
        }
                
        solve(root, 2);
        
        for (int x : t) cout << x << endl;  
        
        ans = t.size();
    }
    
    printf("%lld\n", ans);
    
    return 0;
}