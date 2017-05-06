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

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    vector<ll> d(n);
    for (int i = 0; i < n; i++) scanf("%lld", &d[i]);

    sort(d.begin(), d.end());

    ll md = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        ll diff = abs(d[i] - d[i+1]);
        if (diff < md) ans = 0, md = diff;
        if (diff == md) ans++;
    }

    printf("%lld %d\n", md, ans);

    return 0;
}
