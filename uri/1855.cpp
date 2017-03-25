#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int x, y;
char mat[105][105];
enum {L, U, R, D};
ii dirs[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int getDir(char c)
{
    switch (c) {
        case '>': return R;
        case 'v': return D;
        case '<': return L;
        case '^': return U;
        default: return -1;
    }
}

bool dfs(int i, int j, int dir)
{
    if (dir == -1 || i < 0 || i >= y || j < 0 || j >= x || mat[i][j] == 'V') return false;
    if (mat[i][j] == '*') return true;

    if (mat[i][j] != '.') dir = getDir(mat[i][j]);
    mat[i][j] = 'V';
    return dfs(i + dirs[dir].first, j + dirs[dir].second, dir);
}

int main()
{
    cin >> x >> y;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cin >> mat[i][j];
        }
    }

    bool ans = dfs(0, 0, getDir(mat[0][0]));
    printf("%c\n", ans ? '*' : '!');

    return 0;
}
