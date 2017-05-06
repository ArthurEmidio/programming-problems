#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef pair<int, int> ii;

vector<int> G[int(3e5) + 5];

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> strengths(n + 1);
    int start = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &strengths[i]);
        if (strengths[start] < strengths[i]) {
            start = i;
        }
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(G[i].begin(), G[i].end(), [&strengths](int u, int v) {
            return strengths[u] > strengths[v];
        });
    }

    queue<pair<ii, int>> q;
    set<int> vis;
    q.push({ii(start, 0), 0});
    int ans = strengths[start];

    while (!q.empty()) {
        pair<ii, int> curr = q.front(); q.pop();
        vis.insert(curr.ff.ff);

        int incr = curr.ff.ss;
        if (curr.ss == 1) incr++;
        else if (curr.ss > 1) incr += 2;

        ans = max(ans, strengths[curr.ff.ff] + incr);

        int idx = 0;
        for (int child : G[curr.ff.ff]) {
            if (vis.count(child)) continue;
            q.push({ii(child, idx++), curr.ss+1});
        }
    }

    cout << ans << endl;

    return 0;
}
