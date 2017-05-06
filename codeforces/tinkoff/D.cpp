#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

class UnionFind
{
    vi p, rank;
public:
    UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) {
            p[i] = i;
        }
    }

    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j)) {
            int x = findSet(i);
            int y = findSet(j);

            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

vector<ii> G[85];
set<int> passed;

ll dfs(int u, int k)
{
    if (k == 1) return 0;
    passed.insert(u);

    ll ans = INT_MAX;
    for (const ii &edge : G[u]) {
        int v = edge.ff;
        int w = edge.ss;

        if (!passed.count(v)) {
            passed.erase(u);

            bool possible = true;

            auto greaterThanMin = passed.lower_bound(min(u, v));
            if (greaterThanMin != passed.end()) {
                int number = *greaterThanMin;
                possible = number > max(u, v);
            }

            passed.insert(u);

            if (possible) {
                ans = min(w + dfs(v, k-1), ans);
            }
        }
    }

    passed.erase(u);
    return ans;
}

int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    vector<pair<int, ii>> edges(m + 5);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].ss.ff-1, &edges[i].ss.ss-1, &edges[i].ff);
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        pair<int, ii> p = edges[i];
        if (!uf.isSameSet(p.ss.ff, p.ss.ss)) {
            G[p.ss.ff+1].push_back({p.ss.ss+1, p.ff});
            uf.unionSet(p.ss.ff, p.ss.ss);
        }
    }

    ll ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        passed.clear();
        ans = min(dfs(i, k), ans);
    }

    printf("%lld\n", ans >= INT_MAX ? -1 : ans);

    return 0;
}
