#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }

    ll sum = 0;
    for (int i = 0; i < k; i++) {
        sum += v[i];
    }

    ll S = sum;
    ll N = 1;

    for (int i = k; i < n; i++) {
        sum = sum - v[i - k] + v[i];
        S += sum;
        N++;
    }

    printf("%.10f\n", S / static_cast<double>(N));

    return 0;
}
