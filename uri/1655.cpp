#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (;;) {
        int n, m;
        scanf("%d", &n);
        if (!n) break;
        scanf("%d", &m);

        double mat[105][105] = {};
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            mat[u][v] = mat[v][u] = w / 100.0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = max(mat[i][j], mat[i][k] * mat[k][j]);
                }
            }
        }

        printf("%.6f percent\n", mat[0][n-1] * 100.0);
    }

    return 0;
}
