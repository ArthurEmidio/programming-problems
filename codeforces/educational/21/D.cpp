#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll each;

bool f(const vector<ll> &v)
{
    multiset<ll> all;
    for (ll x : v) all.insert(x);
    if (all.count(each)) return true;

    ll curr = 0;
    bool ans = false;
    for (ll x : v) {
        curr += x;
        all.erase(all.find(x));
        if (all.count(each - curr) || curr == each) {
            ans = true;
            break;
        }
    }

    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
        sum += v[i];
    }

    if (sum % 2 != 0) {
        printf("NO\n");
        return 0;
    }

    each = sum / 2;

    vector<ll> vrev = v;
    reverse(v.begin(), v.end());

    printf("%s\n", f(v) || f(vrev) ? "YES" : "NO");

    return 0;
}
