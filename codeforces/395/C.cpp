#include <bits/stdc++.h>

using namespace std;

#define N (int(1e5) + 5)

vector<int> G[N];
int colors[N];
int root;

int dfs(int v, int p)
{
    int color = colors[v];
    for (int c : G[v]) {
        if (c != p) {
            if (dfs(c, v) != color && !root) root = v;
        }
    }

    return color;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) scanf("%d", &colors[i]);

    dfs(1, -1);

    if (root) {
        int root2 = root;
        root = 0;
        for (int c : G[root2]) dfs(c, root2);
        root = root ? 0 : root2;
    } else root = 1;

    if (root) printf("YES\n%d\n", root);
    else printf("NO\n");

    return 0;
}
