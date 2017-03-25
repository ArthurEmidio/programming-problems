#include <bits/stdc++.h>

using namespace std;

vector<int> G[200005];
int colors[200005];

void dfs(int v, int p)
{
    int curr = 1;
    for (int u : G[v]) {
        if (p == u) continue;
        while (curr == colors[v] || curr == colors[p]) curr++;
        colors[u] = curr++;
        dfs(u, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    G[0].push_back(1);
    dfs(0, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, colors[i]);
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) printf("%d ", colors[i]);
    printf("\n");

    return 0;
}
