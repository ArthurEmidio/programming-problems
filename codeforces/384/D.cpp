#include <bits/stdc++.h>

using namespace std;

#define oo LLONG_MAX
#define mp(i,j) make_pair(i,j)
#define ff first
#define ss second

typedef long long ll;

vector<ll> p;
vector<vector<int>> tree;
unordered_set<int> vis;
ll ans = -oo;

pair<ll,ll> solve(int curr)
{    
    vis.insert(curr);
    
    ll c1 = -oo, c2 = -oo;
    
    pair<ll,ll> res(p[curr], -oo);
    for (int child : tree[curr]) {
        if (vis.count(child)) continue;
        
        auto c = solve(child);
        
        ll m = max(c.ff, c.ss);
        res.ff += c.ff;
        res.ss = max(res.ss, m);
        
        if (c1 < m) c2 = c1, c1 = m;
        else if (c2 < m) c2 = m;
    }
    
    if (c1 != -oo && c2 != -oo) ans = max(c1 + c2, ans);
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    
    tree.assign(n + 1, vector<int>());
    p.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
    }
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    solve(1);
        
    if (ans == -oo) cout << "Impossible" << endl;
    else cout << ans << endl;
    
    return 0;
}
