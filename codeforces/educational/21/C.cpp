#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i].first), v[i].second = i;

    sort(v.begin(), v.end());

    vector<int> cups(n, 0);
    for (int i = 0; i < n; i++) {
        cups[i] = (v[i].first + 1) / 2;
        w -= cups[i];
        v[i].first -= cups[i];
    }

    if (w < 0) {
        printf("-1\n");
        return 0;
    }

    for (int i = n - 1; i >= 0 && w > 0; i--) {
        int q = min(w, v[i].first);
        cups[i] += q;
        w -= q;
    }

    if (w) {
        printf("-1\n");
        return 0;
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[v[i].second] = cups[i];
    }

    for (int a : ans) printf("%d ", a);
    printf("\n");

    return 0;
}
