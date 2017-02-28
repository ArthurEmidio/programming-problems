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

struct SegTree
{
    int n;
    vector<int> st;

    SegTree(int _n) : n(_n), st(4 * _n, 0) {}

    void update(int p, int L, int R, int i, int v)
    {
        if (i < L || i > R) return;
        if (L == R && i == L) st[p] = v;
        else {
            update(2*p, L, (L+R)/2, i, v);
            update(2*p+1, (L+R)/2 + 1, R, i, v);
            st[p] = st[2*p] + st[2*p+1];
        }
    }

    void update(int i, int v)
    {
        update(1, 0, n-1, i, v);
    }

    int query(int p, int L, int R, int i, int j)
    {
        if (i > R || j < L) return 0;
        if (L >= i && R <= j) return st[p];
        return query(2*p, L, (L+R)/2, i, j) + query(2*p+1, (L+R)/2 + 1, R, i, j);
    }

    int query(int i, int j)
    {
        return query(1, 0, n-1, i, j);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    SegTree st(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.update(i, x);
    }

    int l, r;
    while (cin >> l >> r) {
        printf("%d\n", st.query(l, r));
    }

    return 0;
}
