#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MOD 1000000007
#define mp(i,j) make_pair(i,j)

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<vector<ii>> pokemons(m);
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++) {
        int g;
        scanf("%d", &g);
        
        set<int> seen;
        for (int j = 0; j < g; j++) {
            int t;
            scanf("%d", &t);
            t--;
            if (!seen.count(t)) cnt[t] = 0, seen.insert(t);
            cnt[t]++;
        }
        for (int s : seen) pokemons[s].push_back(mp(i, cnt[s]));
    }
    
    sort(pokemons.begin(), pokemons.end());
    
    int f = 1;
    ll ans = 1;
    for (int i = 1; i < m; i++) {
        if (pokemons[i] == pokemons[i-1]) {
            ans = (ans * ++f) % MOD;
        } else f = 1;
    }
    printf("%lld\n", ans);
    
    return 0;
}