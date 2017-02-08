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

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }

    sort(v.begin(), v.end());

    bool ans = false;
    for (int i = 2; i < n && !ans; i++) {
        if (v[i] < v[i-1] + v[i-2]) ans = true;
    }

    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}
