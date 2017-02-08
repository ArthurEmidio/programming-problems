#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef pair<ll,ll> ii;

int main()
{
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    int m;
    scanf("%d", &m);

    vector<ii> mouses(m);
    for (int i = 0; i < m; i++) {
        char tp[5];
        ll p;
        scanf("%lld %s", &p, tp);
        mouses[i] = ii(p, tp[0] == 'U' ? 0 : 1);
    }

    sort(mouses.begin(), mouses.end());

    int i = 0;
    ii ans(0,0);

    while ((a || b || c) && i < m) {
        ii &mouse = mouses[i];
        bool added = false;

        if (mouse.ss == 0 && a) a--, added = true;
        else if (mouse.ss == 1 && b) b--, added = true;
        else if (c) c--, added = true;

        if (added) ans.ff++, ans.ss += mouse.ff;

        i++;
    }

    printf("%lld %lld\n", ans.ff, ans.ss);

    return 0;
}
