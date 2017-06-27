#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool mult(ll a, ll b, ll &ans)
{
    ans = a*b;
    return (ans / a) == b;
}

int main()
{
    ll x, y, l, r;
    cin >> x >> y >> l >> r;

    set<ll> nums;

    ll a = 1;
    do {
        ll b = 1;
        do {
            ll res = a + b;
            if (res > 1e18) break;
            nums.insert(res);
        } while (mult(b, y, b));
    } while (mult(a, x, a));

    ll ans = 0;
    int cnt = 0;
    for (auto it = nums.begin(); it != nums.end(); it++) {
        ll curr = *it;
        if (curr < l || curr > r) continue;
        cnt++;
        ll pv = it == nums.begin() ? l-1 : max(*prev(it), l-1);
        ll nx = next(it) == nums.end() ? r+1 : min(*next(it), r+1);
        ans = max(ans, max(curr - pv, nx - curr) - 1);
    }

    if (!cnt) ans = r - l + 1;

    cout << ans << endl;

    return 0;
}
