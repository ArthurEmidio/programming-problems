#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX

vector<int> tree[200005];

bool getPath(int curr, int p, int v, vector<int> &path)
{
    if (curr == v) {
        path.push_back(curr);
        return true;
    }

    for (int u : tree[curr]) {
        if (u != p && getPath(u, curr, v, path)) {
            path.push_back(curr);
            return true;
        }
    }

    return false;
}

int maxDist(int v, int p)
{
    int ans = 0;
    for (int u : tree[v]) {
        if (u != p) ans = max(ans, maxDist(u, v));
    }
    return 1 + ans;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> path;
    getPath(1, 0, x, path);
    int steps = (path.size() - 2) / 2;

    int ans = 0;
    for (int v : tree[path[steps]]) {
        if (v != path[steps + 1]) {
            ans = max(ans, maxDist(v, path[steps]));
        }
    }

    ans += (path.size() + 1) / 2;
    printf("%d\n", ans*2);

    return 0;
}
