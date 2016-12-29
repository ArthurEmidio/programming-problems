#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<int> colors(n+1);
    int minColor = INT_MAX;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &colors[i]);
        minColor = min(minColor, colors[i]);
    }
    
    vector<vector<int>> edges(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    vector<set<int>> v(100005);
    for (int i = 1; i <= n; i++) {
        for (int nb : edges[i]) {
            if (colors[nb] != colors[i]) v[colors[nb]].insert(colors[i]);
        }
    }
    
    int ans = minColor;
    for (int i = 0; i < v.size(); i++) {
        if (v[ans].size() < v[i].size()) ans = i;
    }
    
    printf("%d\n", ans);
    
    return 0;
}