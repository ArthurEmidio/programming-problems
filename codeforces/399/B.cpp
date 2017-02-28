#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

ll solve(ll i)
{
    if (i == 0 || i == 1) return 1;
    return solve(i / 2)*2 + 1;
}

ll solve2(ll i, ll l, ll r, ll c)
{
    if (i == 0) return 0;

    ll ans = 0;
    if (c >= l && c <= r) ans += (i%2);
    if (c > l) ans += solve2(i/2, l, r < c ? r : c-1, c - (solve(i/2) + 1)/2);
    if (c < r) ans += solve2(i/2, l > c ? l : c+1, r, c + (solve(i/2) + 1)/2);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    ll n, l, r;
    scanf("%lld %lld %lld", &n, &l, &r);

    ll ans = solve(n);
    printf("%lld\n", solve2(n, l, r, (ans+1)/2));

    return 0;
}
