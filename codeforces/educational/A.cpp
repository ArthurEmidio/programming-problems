#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll quant = 0;
    for (ll x = 1; x*x <= n; x++) {
        if (n % x == 0) {
            quant++;
            if (n/x != x) quant++;
        }
    }

    ll ans = -1;
    if (quant >= k) {
        ll i = 0, j = quant+1;
        for (ll x = 1; x*x <= n && ans == -1; x++) {
            if (n % x == 0) {
                i++;
                if (n / x != x) j--;

                if (i == k) ans = x;
                else if (j == k) ans = n/x;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
