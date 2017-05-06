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

ll kadane(const vector<ll> &v)
{
    ll ans = 0;
    ll curr = 0;
    for (ll n : v) {
        curr += n;
        ans = max(ans, curr);
        if (curr < 0) curr = 0;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    vector<ll> v(n);
    for (int i = 0; i < n; i++) scanf("%lld", &v[i]);

    vector<ll> v2(n-1), v3(n-1);
    int x = -1;
    for (int i = 0; i+1 < n; i++) {
        v2[i] = abs(v[i] - v[i+1]) * x;
        v3[i] = v2[i] * -1;
        x = (x == -1) ? 1 : -1;
    }

    printf("%lld\n", max(kadane(v2), kadane(v3)));

    return 0;
}
