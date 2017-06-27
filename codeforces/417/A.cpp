#include <bits/stdc++.h>

using namespace std;

vector<int> v[4] = {{0, 1, 2}, {2, 0, 1}, {1, 2, 0}, {0, 1, 2}};

int main()
{
    int mat[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    bool ans = false;
    for (int i = 0; i < 4 && !ans; i++) {
        if (mat[i][3] == true) {
            for (int j = 0; j < 3; j++) {
                if (mat[i][j]) ans = true;
            }

            int x = 0;
            for (int row = 0; row < 4; row++) {
                if (row == i) continue;
                if (mat[row][v[i][x]]) ans = true;
                x++;
            }
        }
    }

    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}
