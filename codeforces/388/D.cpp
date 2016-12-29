#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
typedef pair<int,int> ii;

set<ii> s;
vector<vector<int>> v;

ii solve(const vector<int> &query)
{
    vector<ii> erased;
    for (int q : query) {
        if (!v[q].empty()) {
            ii x = ii(v[q].back(), q);
            s.erase(x);
            erased.push_back(x);
        }
    }
    
    ii ans(0,0);
    if (!s.empty()) {
        auto firstPlaceIt = prev(s.end());
        ii firstPlace = *firstPlaceIt;
        ii secondPlace = (s.size() == 1) ? ii(0,0) : *prev(firstPlaceIt);
        
        auto it = upper_bound(v[firstPlace.ss].begin(), v[firstPlace.ss].end(), secondPlace.ff);    
        ans = ii(firstPlace.ss, *it);
    }
    
    for (const ii &x : erased) s.insert(x);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    
    v.assign(n+1, vector<int>());
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!v[i].empty()) {
            s.insert(ii(v[i].back(), i));
        }
    }
    
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int k;
        scanf("%d", &k);
        
        vector<int> query(k);
        for (int j = 0; j < k; j++) scanf("%d", &query[j]);
        
        ii ans = solve(query);
        printf("%d %d\n", ans.ff, ans.ss);
    }
    
    return 0;
}
