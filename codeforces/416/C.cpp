#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

int v[5005], start[5005], fin[5005];
vector<pair<pair<int, int>, int>> segments;

int dp[5005][5005];

int solve(int i, int seg_end)
{
    if (i == segments.size()) return 0;

    int &ans = dp[i][seg_end];
    if (ans != -1) return ans;

    ans = solve(i + 1, seg_end);

    if (segments[i].ff.ff >= seg_end) {
        ans = max(ans, segments[i].ss + solve(i + 1, segments[i].ff.ss));
    }

    return ans;
}

int main()
{
    memset(dp, -1, sizeof dp);
    memset(start, -1, sizeof start);
    memset(fin, -1, sizeof fin);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if (start[v[i]] == -1) start[v[i]] = i;
        fin[v[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (i == start[v[i]]) {
            int final_idx = fin[v[i]];
            int comfort = v[i];

            bool valid = true;
            for (int j = i + 1; j <= final_idx; j++) {
                if (start[v[j]] == j) {
                    final_idx = max(final_idx, fin[v[j]]);
                    comfort ^= v[j];
                } else if (start[v[j]] < i) {
                    valid = false;
                    break;
                }
            }

            if (valid) segments.push_back({{i, final_idx}, comfort});
        }
    }

    printf("%d\n", solve(0, 0));

    return 0;
}
