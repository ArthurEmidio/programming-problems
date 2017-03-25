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

vector<int> G[150005];
int vis[150005];
int vis2[150005];

bool dfs(int i, int deg)
{
    if (vis[i]) return true;
    vis[i] = true;

    bool ans = (G[i].size() == deg);
    for (int v : G[i]) {
        if (vis[v]) continue;
        ans = ans && dfs(v, deg);
    }
    return ans;
}

int dfs2(int i)
{
    if (vis2[i]) return 0;
    vis2[i] = true;

    int ans = 1;
    for (int v : G[i]) {
        if (vis2[v]) continue;
        ans += dfs2(v);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool ans = true;
    for (int i = 1; i <= n && ans; i++) {
        if (!vis[i]) {
            int deg = dfs2(i) - 1;
            ans = dfs(i, deg);
        }
    }

    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}
