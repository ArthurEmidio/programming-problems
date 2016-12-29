#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int uf[1005];
set<int> homes;

int find(int x)
{
    return uf[x] == x ? x : uf[x] = find(uf[x]);
}

void merge(int x, int y)
{
    int i = find(x), j = find(y);
    if (i != j) {
        if (homes.count(i)) uf[j] = i;
        else uf[i] = j;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 0; i < n; i++) {
        uf[i] = i;
    }
    
    for (int i = 0; i < k; i++) {
        int c;
        scanf("%d", &c);
        homes.insert(c-1);
    }
    
    vector<ll> edges(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u-1]++;
        merge(u-1, v-1);
    }

    ll vertices = 0;
    ll edgeCount = 0;
    vector<ll> homeSizes(n, 0);
    vector<ll> edgesHome(n, 0);
    for (int i = 0; i < n; i++) {
        int parent = find(i);
        if (homes.count(parent)) {
            edgesHome[parent] += edges[i];
            homeSizes[parent]++;
        } else {
            edgeCount += edges[i];
            vertices++;
        }
    }
    
    ll complete = vertices ? (vertices*(vertices-1)/2) - edgeCount : 0;
    pair<ll,ll> ans(0,0);
    ll acc = 0;
    for (int i : homes) {
        ll homeSize = homeSizes[i];
        ll homeEdges = edgesHome[i];
        
        ll val = homeSize * (homeSize-1)/2 - homeEdges;
        if (val + (homeSize * vertices) > ans.first + ans.second) {
            ans = make_pair(val, homeSize * vertices);
        }
        
        acc += val;
    }
    
    printf("%lld\n", ans.second + acc + complete);
    
    return 0;
}
