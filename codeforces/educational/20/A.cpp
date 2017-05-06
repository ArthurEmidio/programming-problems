#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    if (k > n*n) {
        printf("-1\n");
        return 0;
    }

    int mat[105][105] = {};
    int i = 0;
    for (i = 0; i < n && k >= 2; i++) {
        for (int j = 0; j < n && k >= 2; j++) {
            if (mat[i][j]) continue;
            mat[i][j] = mat[j][i] = 1;
            k -= (i == j) ? 1 : 2;
        }
    }

    if (k) {
        if (mat[i][i]) i++;
        mat[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
