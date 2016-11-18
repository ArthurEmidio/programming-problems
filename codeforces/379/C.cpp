#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m, k, x, s;
    scanf("%d %d %d %d %d", &n, &m, &k, &x, &s);
    
    vector<int> p1_effect(m + 1, x), p1_cost(m + 1, 0);
    for (int i = 1; i <= m; i++) scanf("%d", &p1_effect[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &p1_cost[i]);
    
    vector<int> p2_effect(k), p2_cost(k);
    for (int i = 0; i < k; i++) scanf("%d", &p2_effect[i]);
    for (int i = 0; i < k; i++) scanf("%d", &p2_cost[i]);
    
    long long ans = numeric_limits<long long>::max();
    for (int i = 0; i <= m; i++) {
        int manaLeft = s - p1_cost[i];
        if (manaLeft < 0) continue;
        
        long long prepTime = p1_effect[i];
        long long leftToPrepare = n;
        
        auto it = upper_bound(p2_cost.begin(), p2_cost.end(), manaLeft);
        if (it != p2_cost.begin()) {
            int idx = prev(it) - p2_cost.begin();
            leftToPrepare -= p2_effect[idx];
        }
        
        ans = min(ans, prepTime * leftToPrepare);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
