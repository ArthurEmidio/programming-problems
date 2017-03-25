#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<pair<ll, ll>, ll> dists;

void query(ll u, ll v)
{
    ll ans = 0;
    while (u != v) {
        if (u > v) swap(u, v);
        ans += dists[{v/2, v}];
        v /= 2;
    }
    printf("%lld\n", ans);
}

void add(ll u, ll v, ll d)
{
    while (u != v) {
        if (u > v) swap(u, v);
        dists[{v/2, v}] += d;
        v /= 2;
    }
}

int main()
{
    int q;
    scanf("%d", &q);

    while (q--) {
        ll t, u, v;
        scanf("%lld %lld %lld", &t, &u, &v);
        if (t == 1) {
            ll d;
            scanf("%lld", &d);
            add(u, v, d);
        } else query(u, v);
    }

    return 0;
}
