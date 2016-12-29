#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v;
vector<ll> u;

inline ll rsq(int L, int R)
{
    return u[R + 1] - u[L];
}

ll f(int x, int k)
{
    ll target = v[x+1];
    ll begin = 0;
    ll end = x;
    
    ll n;
    for (;;) {
        ll mid = (begin + end) / 2;
        n = x - mid + 1;
        ll rem = n*target - rsq(mid, x);
        
        if (mid == 0 && k-rem >= 0) break;
        if (mid > 0 && k >= rem && k-rem < target - v[mid-1]) break;
        if (mid == x && k < rem) return 0;
        
        if (k < rem) begin = mid + 1;
        else if end = mid - 1;
        else break;
    }
    
    return n;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    sort(v.begin(), v.end());
    
    u.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        u[i] = v[i-1] + u[i-1];
    }
    
    ll ans, maxQuant = -1;
    for (int i = 0; i < n;) {
        int curr = v[i];
        
        ll j = i;
        while (i < n && v[i] == curr) i++;
        
        ll quant = i - j;
        if (j > 0) quant += f(j-1, k);
        if (quant > maxQuant) {
            maxQuant = quant;
            ans = curr;
        }
    }
    
    printf("%lld %lld\n", maxQuant, ans);
    
    return 0;
}
