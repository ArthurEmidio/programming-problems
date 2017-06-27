#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mat[20][105];
int dp[20][2];
int n, m;
int first = -1;

int solve(int f, int dir)
{
    int &ans = dp[f][dir];
    if (ans != -1) return ans;

    int steps, pos;
    if (dir) {
        pos = 0;
        for (int i = 0; i < m; i++) {
            if (mat[f][i] == 1) pos = i;
        }
        steps = pos;
    } else {
        pos = m - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (mat[f][i] == 1) pos = i;
        }
        steps = (m - 1) - pos;
    }

    if (f == first) return ans = steps;

    return ans = 1 + steps + min(solve(f - 1, 1) + pos, solve(f - 1, 0) + ((m - 1) - pos));
}

int main()
{
    memset(dp, -1, sizeof dp);

    cin >> n >> m;
    m += 2;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            mat[i][j] = row[j] == '1' ? 1 : 0;
            if (first == -1 && mat[i][j]) first = i;
        }
    }

    printf("%d\n", first == -1 ? 0 : solve(n - 1, 1));

    return 0;
}
