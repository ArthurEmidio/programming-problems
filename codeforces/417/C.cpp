#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, s;
ll v[100005];

ll f(ll k)
{
    vector<ll> tmp;
    for (int i = 0; i < n; i++) {
        tmp.push_back(v[i] + (i + 1)*k);
    }

    sort(tmp.begin(), tmp.end());

    ll sum = 0;
    for (int i = 0; i < k; i++) {
        sum += tmp[i];
    }
    
    return sum;
}

int main()
{
    scanf("%lld %lld", &n, &s);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }

    ll left = 0;
    ll right = n;

    while (left < right) {
        ll k = (left + right) / 2 + 1;
        if (f(k) <= s) left = k;
        else right = k - 1;
    }

    printf("%lld %lld\n", left, f(left));

    return 0;
}
