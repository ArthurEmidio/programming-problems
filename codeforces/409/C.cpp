#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef pair<ll, ll> ii;

int n, p;
vector<ii> devices;

double f(double t)
{
    double sum = 0;
    for (const ii &d : devices) {
        sum += max(0.0, t * d.ff - d.ss);
    }
    return sum / t;
}

int main()
{
    scanf("%d %d", &n, &p);

    ll sumA = 0;
    devices.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &devices[i].ff, &devices[i].ss);
        sumA += devices[i].ff;
    }

    if (p >= sumA) {
        printf("-1\n");
        return 0;
    }

    double l = 0;
    double r = 1e18;

    for (int i = 0; i < 100; i++) {
        double mid = l + (r - l) / 2;
        if (p >= f(mid)) l = mid;
        else r = mid;
    }

    printf("%.10f\n", l);

    return 0;
}
