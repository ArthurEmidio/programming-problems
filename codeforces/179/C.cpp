#include <bits/stdc++.h>

using namespace std;

#define LSOne(i) (i & (-i))
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> Op;

class FenwickTree
{
    vector<ll> tree;
    
public:
    FenwickTree(ll n)
    {
        tree.assign(n + 1, 0);
    }

    ll query(ll i) const
    {
        ll sum = 0;
        for (; i > 0; i -= LSOne(i)) sum += tree[i];
        return sum;
    }

    void adjust(ll i, ll v)
    {
        for (; i < tree.size(); i += LSOne(i)) tree[i] += v;
    }
    
    void add(ll l, ll r, ll v)
    {
        adjust(l, v);
        adjust(r+1, -v);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    FenwickTree ft1(n);
    for (int i = 1; i <= n; i++) {
        int v;
        scanf("%d", &v);
        ft1.add(i, i, v);
    }
    
    vector<Op> ops(m);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        ops[i] = mp(mp(l,r), d);
    }
    
    FenwickTree ft2(m);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ft2.add(x, y, 1);
    }
    
    for (int i = 0; i < m; i++) {
        ft1.add(ops[i].first.first, ops[i].first.second, ops[i].second * ft2.query(i+1));
    }
    
    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%lld", ft1.query(i));
    }
    printf("\n");
    
    return 0;
}
