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

    ll b1, q, l, m;
    scanf("%lld %lld %lld %lld", &b1, &q, &l, &m);

    set<ll> nope;
    bool inf = false;
    for (int i = 0; i < m; i++) {
        ll x;
        scanf("%lld", &x);
        nope.insert(x);
    }

    if (abs(b1) > l) {
        printf("0\n");
        return 0;
    }

    ll ans = 0;
    if (q == 0 || b1 == 0) {
        if (nope.count(b1) && nope.count(0)) {
            printf("0\n"); return 0;
        }

        if (nope.count(0)) ans = 1;
        else inf = true;
    } else if (q == 1) {
        if (nope.count(b1)) {
            printf("0\n"); return 0;
        }

        if (abs(b1) > l) ans = 0;
        else inf = true;
    } else if (q == -1) {
        ll b2 = b1 * q;
        if (nope.count(b1) && nope.count(b2)) {
            printf("0\n"); return 0;
        }

        if (abs(b1) > l) ans = 0;
        else inf = true;
    } else {
        ll curr = b1;
        while (1) {
            if (!nope.count(curr)) {
                if (abs(curr) > l) break;
                ans++;
            }
            curr *= q;
        }
    }

    if (inf) printf("inf\n");
    else printf("%lld\n", ans);

    return 0;
}
