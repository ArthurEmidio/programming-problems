#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> t;
vector<ll> values;

pair<ll, ll> dfs(int v, int p)
{    
    pair<ll, ll> ans(0, 0);
    for (int c : t[v]) {
        if (c == p) continue;
        pair<ll, ll> x = dfs(c, v);
        ans.first = min(ans.first, x.first);
        ans.second = max(ans.second, x.second);
    }
    
    ll add = values[v] - ans.second - ans.first;
    if (add < 0) ans.first += add;
    else ans.second += add;
    
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    t.assign(n + 1, vector<ll>());
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        t[a].push_back(b);
        t[b].push_back(a);
    }
    
    values.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &values[i]);
    }

    pair<ll,ll> res = dfs(1, -1);
    printf("%lld\n", abs(res.first) + abs(res.second));
    
    return 0;
}