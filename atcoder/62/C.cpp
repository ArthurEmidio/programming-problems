#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll max(ll a, ll b, ll c)
{
    return max(max(a, b), c);
}

ll min(ll a, ll b, ll c)
{
    return min(min(a, b), c);
}

int main()
{
    ll h, w;
    cin >> h >> w;

    ll ans = 1e12;

    for (int i = 1; i <= h; i++) {
        ll x = i * w;
        ll y = ((h - i) / 2) * w;
        ll z = ((h - i + 1) / 2) * w;
        ll res = max(x, y, z) - min(x, y, z);
        ans = min(ans, res);
    }

    for (int i = 1; i <= h; i++) {
        ll x = i * w;
        ll y = (w / 2) * (h - i);
        ll z = ((w + 1) / 2) * (h - i);
        ll res = max(x, y, z) - min(x, y, z);
        ans = min(ans, res);
    }

    for (int i = 1; i <= w; i++) {
        ll x = i * h;
        ll y = ((w - i) / 2) * h;
        ll z = ((w - i + 1) / 2) * h;
        ll res = max(x, y, z) - min(x, y, z);
        ans = min(ans, res);
    }

    for (int i = 1; i <= w; i++) {
        ll x = i * h;
        ll y = (w - i) * (h / 2);
        ll z = (w - i) * ((h + 1) / 2);
        ll res = max(x, y, z) - min(x, y, z);
        ans = min(ans, res);
    }

    cout << ans << endl;

    return 0;
}
