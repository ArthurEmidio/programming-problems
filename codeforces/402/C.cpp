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

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k;
    scanf("%d %d", &n, &k);

    vector<ii> prices(n);
    for (int i = 0; i < n; i++) scanf("%d", &prices[i].ff);
    for (int i = 0; i < n; i++) scanf("%d", &prices[i].ss);

    ll ans = 0;
    vector<ii> later;
    for (int i = 0; i < n; i++) {
        if (prices[i].ff <= prices[i].ss) ans += prices[i].ff;
        else later.push_back(prices[i]);
    }

    sort(later.begin(), later.end(), [](const ii &p1, const ii &p2) {
        return (p1.ff - p1.ss) < (p2.ff - p2.ss);
    });

    int i = 0;
    k -= n - later.size();
    while (i < k) ans += later[i++].ff;
    while (i < later.size()) ans += later[i++].ss;

    printf("%lld\n", ans);

    return 0;
}
