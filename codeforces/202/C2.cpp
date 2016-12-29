#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<ll> v(n);
    ll m = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
        m = max(m, v[i]);
    }
    
    ll sum = 0;
    for (ll x : v) sum += x;
    ll ans = ceil(sum / static_cast<double>(n-1));
        
    printf("%lld\n", max(ans, m));
    
    return 0;
}
