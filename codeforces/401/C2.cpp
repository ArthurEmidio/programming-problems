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
    vector<vector<int>> look(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        int j = 1;
        look[0][i] = 1;

        while (j < n) {
            while (j < n && M[j][i] < M[j-1][i]) look[j++][i] = 1;
            if (j == n) break;

            int k = j-1;
            while (j < n && M[j][i] >= M[j-1][i]) look[j][i] = (j - k + 1), j++;
        }
    }

    vector<int> look2(n, 0);
    for (int i = 0; i < n; i++) {
        int rmax = 0;
        for (int j = 0; j < m; j++) rmax = max(rmax, look[i][j]);
        look2[i] = rmax;
    }

    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        if (look2[r-1] >= r-l+1) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
