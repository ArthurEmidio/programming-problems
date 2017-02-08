#include <bits/stdc++.h>

using namespace std;

#define LSOne(i) (i & (-i))

typedef long long ll;

class Bit
{
    vector<ll> ft;
    int n;
    
public:
    Bit(int _n) : n(_n)
    {
        ft.assign(n + 1, 0);
    }
    
    void add(int i, ll v)
    {
        for (; i < ft.size(); i += LSOne(i)) ft[i] += v;
    }
    
    ll query(int i)
    {
        ll ans = 0;
        for (; i; i -= LSOne(i)) ans += ft[i];
        return ans;
    }
};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    k = min(k, n - k);
    
    int x = 1, t = n;
    ll ans = 1;
    Bit bit(n);
    while (t--) {
        int old = x;
        x += k;
        
        if (x > n) {
            x -= n;
            ans += 1 + bit.query(n) - bit.query(old) + bit.query(x-1);
        } else ans += 1 + bit.query(x-1) - bit.query(old);
        
        bit.add(old, 1);
        bit.add(x, 1);
        printf("%lld ", ans);
    }
    printf("\n");
    
    return 0;
}
     