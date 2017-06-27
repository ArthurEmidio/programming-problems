#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool f(ll x, ll y, ll p, ll q, ll n)
{
    p *= n;
    q *= n;
    return p >= x && q >= y && (q - y) >= (p - x);
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;

        if (!p && p == x) {
            printf("0\n");
            continue;
        }

        ll l = 0;
        ll r = 1e10;

        while (l < r) {
            ll mid = (l + r) / 2;
            if (f(x, y, p, q, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (l == 1e10) printf("-1\n");
        else printf("%lld\n", l * q - y);
    }

    return 0;
}
