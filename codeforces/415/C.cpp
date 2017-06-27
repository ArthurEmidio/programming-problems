#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int main()
{
    ll pwr2[300005] = {1};
    for (int i = 1; i < 300005; i++) pwr2[i] = (pwr2[i - 1] * 2) % MOD;

    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int left = i;
        int right = n - i - 1;

        ll onLeft = pwr2[left] - 1;
        ll onRight = pwr2[right] - 1;

        ans = ans + (onLeft - onRight) * v[i];
        if (ans < 0) ans = (ans % MOD) + MOD;
        ans = ans % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
