#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    
    vector<ll> v(n);
    for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
    
    sort(v.begin(), v.end(), std::greater<ll>());
    
    ll x = log2(sqrt(n)) + 1;
    ll times = 3;
    ll orig = times;
    ll ans = x*v[0];
    x--;
    
    for (int i = 1; i < n; i++) {
        ans += x * v[i];
                
        times--;
        if (times == 0) {
            times = orig*4;
            orig = times;
            x--;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
