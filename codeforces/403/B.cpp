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
typedef pair<int, int> ii;

int n;
ii v[60005];

double f(double x)
{
    double ans = 0;
    for (int i = 0; i < n; i++) {
        double t = fabs(v[i].ff - x) / v[i].ss;
        ans = max(ans, t);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &v[i].ff);
    for (int i = 0; i < n; i++) scanf("%d", &v[i].ss);

    double l = 0, r = 1000000005;
    for (int i = 0; i < 300; i++) {
        double m1 = l + (r - l)/3;
        double m2 = r - (r - l)/3;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }

    printf("%.10f\n", f(l));

    return 0;
}
