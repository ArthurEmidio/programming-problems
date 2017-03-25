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

    int n, m;
    scanf("%d %d", &n, &m);

    bool ans = false;
    for (int i = 0; i < m; i++) {
        set<int> st;
        int k;
        scanf("%d", &k);

        bool pos = true;
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            st.insert(v);
            if (st.count(-v)) pos = false;
        }
        if (pos) ans = true;
    }

    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}
