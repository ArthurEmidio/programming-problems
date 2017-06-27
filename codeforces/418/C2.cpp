#include <bits/stdc++.h>

using namespace std;

int n;
char s[1505];
int ans[26][1505];

int main()
{
    scanf("%d %s", &n, s);

    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < n; i++) {
            int changes = 0;
            for (int j = i; j < n; j++) {
                if (s[j] != c) changes++;
                ans[c - 'a'][changes] = max(ans[c - 'a'][changes], j - i + 1);
            }
        }
        for (int j = 1; j < 1505; j++) {
            ans[c - 'a'][j] = max(ans[c - 'a'][j], ans[c - 'a'][j - 1]);
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
