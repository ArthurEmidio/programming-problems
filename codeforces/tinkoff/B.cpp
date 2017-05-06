#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> ii;

int n, m;
char grid[1005][1005];
short dp[1005][1005][5][5];

enum {
    LEFT, RIGHT, UP, DOWN
};

short solve(int i, int j, int dir, int turns)
{
    if (i < 0 || j < 0 || i >= n || j >= m || turns > 2) return false;
    if (grid[i][j] == 'T') return true;
    if (grid[i][j] != '.') return false;

    short &ans = dp[i][j][dir][turns];
    if (ans != -1) return ans;

    grid[i][j] = '?';

    ans = solve(i + 1, j, DOWN, dir == DOWN ? turns : turns+1) ||
               solve(i - 1, j, UP, dir == UP ? turns : turns+1) ||
               solve(i, j - 1, LEFT, dir == LEFT ? turns : turns+1) ||
               solve(i, j + 1, RIGHT, dir == RIGHT ? turns : turns+1);

    grid[i][j] = '.';

    return ans;
}

int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> m;

    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start = {i, j};
                grid[i][j] = '.';
            }
        }
    }

    bool ans = solve(start.ff, start.ss, LEFT, 0) || solve(start.ff, start.ss, RIGHT, 0) || solve(start.ff, start.ss, UP, 0) || solve(start.ff, start.ss, DOWN, 0);
    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}
