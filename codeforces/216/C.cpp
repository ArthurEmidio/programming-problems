#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

vector<int> edges[100005];
set<ii> probls;
vector<int> res;

int dfs(int v, int p)
{        
    int ans = 0;
    for (int nb : edges[v]) {
        if (p == nb) continue;
        
        int x = dfs(nb, v);
        if (probls.count({v, nb})) {
            if (x) ans += x;
            else {
                res.push_back(nb);
                ans++;
            }
        } else ans += x;
    }
    
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
        
    for (int i = 0; i < n-1; i++) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        edges[x].push_back(y);
        edges[y].push_back(x);
        if (t == 2) {
            probls.insert({x,y});
            probls.insert({y,x});
        }
    }
    
    printf("%d\n", dfs(1, -1));
    for (int a : res) printf("%d ", a);
    printf("\n");
    
    return 0;
}