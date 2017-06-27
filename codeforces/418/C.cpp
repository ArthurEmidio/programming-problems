#include <bits/stdc++.h>

using namespace std;

int n;
char s[1505];
int ans[26][1505];

int main()
{
    scanf("%d %s", &n, s);

    vector<vector<int>> bef(26, vector<int>(n));
    for (char c = 'a'; c <= 'z'; c++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != c) cnt++;
            bef[c - 'a'][i] = cnt;
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 1; i <= n; i++) {
            const vector<int> &row = bef[c - 'a'];
            for (int j = 0; j < n; j++) {
                int q = upper_bound(row.begin() + j, row.end(), row[j] + i - (s[j] != c)) - (row.begin() + j);
                ans[c - 'a'][i] = max(ans[c - 'a'][i], q);
            }
        }
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int m;
        char c;
        scanf("%d %c", &m, &c);
        printf("%d\n", ans[c - 'a'][m]);
    }

    return 0;
}
