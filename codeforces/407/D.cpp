#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

vector<int> G[int(1e6) + 5];
bool vis[int(1e6) + 5];
bool hasLoop[int(1e6) + 5];

void dfs(int v)
{
    if (vis[v]) return;
    vis[v] = true;
    for (int u : G[v]) dfs(u);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    scanf("%d %d", &n, &m);

    ll loop = 0;
    ll normal = 0;

    int x;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == v) loop++, hasLoop[u] = true;
        else {
            x = u;
            G[u].push_back(v);
            G[v].push_back(u);
            normal++;
        }
    }

    dfs(x);
    bool valid = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && (G[i].size() > 0 || hasLoop[i])) valid = false;
    }

    ll ans = 0;
    if (valid) {
        ans = loop*(loop-1)/2 + normal*loop;
        for (int i = 1; i <= n; i++) {
            ll degree = G[i].size();
            ans += (degree * (degree - 1)) / 2;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
