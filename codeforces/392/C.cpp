#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);

    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;

    ll mi = 0, ma = 0, ans = 0;
    if (n == 1 || n == 2) {
        if (n == 2) m *= 2, y *= x;
        ll cycles = k / m;
        mi = cycles;
        ma = ((k % m) == 0) ? cycles : cycles+1;
        ans = y > (k % m) ? mi : ma;
    } else {
        ll cycles = k / (2 * m * (n-1));
        k = k % (2 * m * (n-1));

        mi = (k < m*n) ? cycles : cycles+1;

        ma = cycles * 2;
        if (k > m) ma++;
        if (k > m*n) ma++;

        if (x == 1) ans = (k < y) ? cycles : cycles+1;
        else if (x == n) ans = (k < (n - 1)*m + y) ? cycles : cycles+1;
        else {
            ans = cycles * 2;
            if (k >= (x - 1)*m + y) ans++;
            if (k >= m*n + (n - x - 1)*m + y) ans++;
        }
    }

    printf("%lld %lld %lld\n", max((ll)1, ma), mi, ans);

    return 0;
}
