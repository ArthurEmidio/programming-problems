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

    ll a, b;
    cin >> a >> b;

    int ans = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
