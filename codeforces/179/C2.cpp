#include <bits/stdc++.h>

using namespace std;

#define mp(i,j) make_pair(i,j)
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> Op;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    vector<ll> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        a[i] += x;
        a[i+1] -= x;
    }
        
    vector<Op> ops(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &ops[i].ff.ff, &ops[i].ff.ss, &ops[i].ss);
        ops[i].ff.ff--, ops[i].ff.ss--;
    }

    vector<int> opQuant(m + 1, 0);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;

        opQuant[x]++;
        opQuant[y+1]--;
    }

    ll quant = 0;
    for (int i = 0; i < m; i++) {        
        quant += opQuant[i];
        ll add = ops[i].ss * quant;

        a[ops[i].ff.ff] += add;
        a[ops[i].ff.ss + 1] -= add;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
        if (i > 0) printf(" ");
        printf("%lld", ans);
    }
    printf("\n");
    
    return 0;
}