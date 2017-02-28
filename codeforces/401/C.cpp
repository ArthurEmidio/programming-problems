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

    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> M(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    vector<ii> ranges;
    for (int i = 0; i < m; i++) {
        int j = 0;
        while (j < n) {
            while (j+1 < n && M[j][i] > M[j+1][i]) j++;
            if (j+1 == n) break;

            int k = j;
            j++;
            while (j < n && M[j][i] >= M[j-1][i]) j++;

            // k to j-1
            ranges.push_back(ii(k+1, j));
        }
    }

    sort(ranges.begin(), ranges.end(), [](const ii &p1, const ii &p2) {
        return p1.ff == p2.ff ? (p1.ss > p2.ss) : (p1.ff < p2.ff);
    });

    vector<ii> ranges2;
    for (int i = 0; i < ranges.size();) {
        int j = i+1;
        int r = ranges[i].ss;
        while (j < ranges.size() && ranges[i].ss >= ranges[j].ss) r = max(r, ranges[j++].ss);

        ranges2.push_back(ii(ranges[i].ff, r));

        i = j;
    }

    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        auto it = upper_bound(ranges2.begin(), ranges2.end(), ii(l, INT_MAX));
        bool ans = l == r;
        if (!ranges2.empty() && it != ranges2.begin()) {
            it = prev(it);
            ii rg = *it;
            if (rg.ff <= l && rg.ss >= r) ans = true;
        }
        printf("%s\n", ans ? "Yes" : "No");
    }

    return 0;
}
