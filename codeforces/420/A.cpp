#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int m[55][55];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    bool pos = true;
    for (int i = 0; i < n && pos; i++) {
        for (int j = 0; j < n && pos; j++) {
            if (m[i][j] == 1) continue;
            pos = false;
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                int target = m[i][j] - m[i][k];
                for (int l = 0; l < n; l++) {
                    if (m[l][j] == target && l != i) pos = true;
                }
            }
        }
    }

    printf("%s\n", pos ? "Yes" : "No");

    return 0;
}
