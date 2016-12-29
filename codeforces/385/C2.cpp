#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vector<int>> graph;
vector<int> edges;
set<int> vis;
set<int> homes;

ii dfs(int v)
{
    if (vis.count(v)) return ii(0,0);
    vis.insert(v);
    
    ii ans(1, edges[v]);
    for (int neighbor : graph[v]) {
        ii res = dfs(neighbor);
        ans.first += res.first;
        ans.second += res.second;
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 0; i < k; i++) {
        int c;
        scanf("%d", &c);
        homes.insert(c-1);
    }
    
    graph.assign(n, vector<int>());
    edges.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges[u]++;
    }
    
    vector<ii> homeComponents;
    for (int home : homes) {
        homeComponents.push_back(dfs(home));
    }

    int otherVertices = 0;
    int otherEdges = 0;
    for (int i = 0; i < n; i++) {
        if (!vis.count(i)) {
            ii component = dfs(i);
            otherVertices += component.first;
            otherEdges += component.second;
        }
    }
    int ans = otherVertices ? otherVertices * (otherVertices-1)/2 - otherEdges : 0;

    ii best(0,0);
    for (const ii &component : homeComponents) {
        int val = component.first * (component.first - 1)/2 - component.second;
        ans += val;

        if (val + otherVertices * component.first > best.first + otherVertices * best.second) {
            best = make_pair(val, component.first);
        }
    }
    ans += otherVertices * best.second;

    printf("%d\n", ans);
    
    return 0;
}