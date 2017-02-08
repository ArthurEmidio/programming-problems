#include <bits/stdc++.h>

using namespace std;

#define LSOne(i) i&(-i)

typedef long long ll;

ll ft[1000005];
int n;

void add(int i, ll v)
{
    for (; i <= n; i += LSOne(i)) ft[i] += v;
}

ll query(int i)
{
    ll ans = 0;
    for (; i; i -= LSOne(i)) ans += ft[i];
    return ans;
}

int main()
{
    int k;
    scanf("%d %d", &n, &k);
    k = min(k, n - k);
    
    ll ans = 1;
    int x = 1;
    for (int i = 0; i < n; i++) {
        int b = x;
        x += k;
        
        if (x > n) {
            x -= n;
            ans += 1 + query(n) - query(b) + query(x-1);
        } else ans += 1 + query(x-1) - query(b);
        
        add(b, 1);
        add(x, 1);
        
        printf("%lld ", ans);
    }
    printf("\n");
    
    return 0;
}