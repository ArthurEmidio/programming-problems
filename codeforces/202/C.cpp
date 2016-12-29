#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll x, ll n)
{    
    ll a = x/(n-1);
    ll rem = x%(n-1);
    ll ans = n*a;
    ans += rem ? rem+1 : 0;
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<ll> v(n);
    for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
    
    sort(v.begin(), v.end());
    
    ll largest = v.back(), ans = 0;
    for (int i = 1; i < v.size(); i++) {
        v[i] -= ans;
        ll diff = (v[i] - v[i-1]) * i;
        v[i] -= diff;
        ans += diff;        
    }
    
    ans = v.back() < 0 ? (largest) : (ans + f(v.back(), n));
    
    printf("%lld\n", ans);
    
    return 0;
}
