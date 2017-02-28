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

struct ring
{
    int a, b;
    ll h;
};

struct SegTree
{
    vector<ll> st;
    int n;

    SegTree(int _n) : n(_n)
    {
        st.assign(8 * n, 0);
    }

    void update(int p, int L, int R, int i, ll v)
    {
        if (i < L || i > R) return;
        if (L == R && i == L) st[p] = max(v, st[p]);
        else {
            update(2*p, L, (L + R) / 2, i, v);
            update(2*p+1, (L+R) / 2 + 1, R, i, v);
            st[p] = max(st[2*p], st[2*p+1]);
        }
    }

    void update(int i, ll v)
    {
        update(1, 0, n-1, i, v);
    }

    ll query(int p, int L, int R, int i, int j)
    {
        if (i > R || j < L) return 0;
        if (L >= i && R <= j) return st[p];
        return max(query(2*p, L, (L+R)/2, i, j), query(2*p+1, (L+R)/2 + 1, R, i, j));
    }

    ll query(int i, int j)
    {
        return query(1, 0, n-1, i, j);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    vector<ring> rings(n);
    map<int, int> m;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %lld", &rings[i].a, &rings[i].b, &rings[i].h);
        v.push_back(rings[i].a);
        v.push_back(rings[i].b);
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    for (int x : v) if (!m.count(x)) m[x] = cnt++;

    for (int i = 0; i < n; i++) {
        rings[i].a = m[rings[i].a];
        rings[i].b = m[rings[i].b];
    }

    sort(rings.begin(), rings.end(), [](const ring &r1, const ring &r2) {
        return (r1.b == r2.b) ? (r1.a < r2.a) : (r1.b > r2.b);
    });

    SegTree st(cnt + 50);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x = rings[i].h + st.query(0, rings[i].b-1);
        ans = max(ans, x);
        st.update(rings[i].a, x);
    }

    printf("%lld\n", ans);

    return 0;
}
