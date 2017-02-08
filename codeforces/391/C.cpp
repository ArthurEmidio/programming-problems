#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MOD 1000000007
#define mp(i,j) make_pair(i,j)

int main()
{
    ll fact[1000005] = {1, 1};
    for (int i = 2; i <= 1000000; i++) fact[i] = (fact[i-1] * i) % MOD;
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<int> gymTypes(m, 0);
    vector<vector<ii>> pokemons(m);
    for (int i = 0; i < n; i++) {
        int g;
        scanf("%d", &g);
        
        set<int> pok;
        for (int j = 0; j < g; j++) {
            int t;
            scanf("%d", &t);
            t--;
            
            if (!pok.count(t)) {
                pok.insert(t);
                gymTypes[t] = 0;
            }
            gymTypes[t]++;
        }
        
        for (int p : pok) pokemons[p].push_back(mp(i, gymTypes[p]));
    }
    
    map<vector<ii>, int> components;
    for (int i = 0; i < m; i++) components[pokemons[i]]++;
    
    ll ans = 1;
    for (const auto &x : components) ans = (ans * fact[x.second]) % MOD;
    printf("%lld\n", ans);
    
    return 0;
}