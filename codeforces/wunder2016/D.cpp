#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> edges;
ll edgesAns = 0;

bool dfs(int node, int p)
{
    int cnt = 0;
    vector<int> &children = edges[node];
    for (int child : children) {
        if (child != p) {
            cnt += dfs(child, node);
        }
    }
    
    if (cnt <= 1) {
        edgesAns += cnt;
        return true;
    }
    
    edgesAns += 2;
    return false;
}

int main()
{
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
        
        dfs(root, -1);
        ans = (n-1-edgesAns)*y + edgesAns*x;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}