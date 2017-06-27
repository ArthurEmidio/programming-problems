#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bruteforce(ll n, ll m)
{
    ll cnt = m;
    ll orig = n;
    while (n > 0) {
        n = min(orig, n + m);
        n -= cnt++;
    }
    return cnt-1;
}

ll f(ll n, ll m)
{
    if (n <= m) {
        return n;
    }

    ll left = 0;
    ll right = 1000000000LL;

    while (left < right) {
        ll x = (left + right) / 2;

        ll res = n + m*x - ((x + m + 1)*(x + m + 2)/2 - m*(m + 1)/2);
        cout << m*x << endl;

        if (res <= 0) {
            right = x;
        } else {
            left = x + 1;
        }
    }

    cout << left << endl;

    return left + m + 1;
}

int main()
{
    // for (int i = 1; i < 100; i++) {
    //     for (int j = i + 1; j < 100; j++) {
    //         assert(f(j, i) == bruteforce(j, i));
    //     }
    // }

    // n + m*(x) - ((x+m+1) * (x+m+2)/2 - m*(m+1)/2)
    //
    ll n, m;
    cin >> n >> m;
    cout << f(n, m) << endl;

    // cout << (f(1e16, 1) == bruteforce(1e16, 1)) << endl;

    // cout << bruteforce(,1) << endl;


    // cout << f(10000000000LL, 10000000000LL - 1LL) << endl;
    // cout << bruteforce(10000000000LL, 10000000000LL - 1LL) << endl;

    // for (int m = 1; m < 10000; m++) {
    //     cout << m << endl;
    //     assert(f(1e12, m) == bruteforce(1e12, m));
        // for (int n = m; n < 10000; n++) {
    //         if (bruteforce(n, m) != f(n, m)) {
    //             cout << n << " " << m << endl;
    //         }
    //     }
    // }

    // cout << left+m+1 << endl;

    return 0;
}
