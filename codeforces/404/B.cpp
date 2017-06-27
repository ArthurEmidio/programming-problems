#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    pair<int, int> p1min(INT_MAX, INT_MAX), p1max(INT_MIN, INT_MIN);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (r < p1min.second) p1min = {l, r};
        if (l > p1max.first) p1max = {l, r};
    }

    int m;
    scanf("%d", &m);

    pair<int, int> p2min(INT_MAX, INT_MAX), p2max(INT_MIN, INT_MIN);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (r < p2min.second) p2min = {l, r};
        if (l > p2max.first) p2max = {l, r};
    }

    printf("%d\n", max(0, max(p2max.first - p1min.second, p1max.first - p2min.second)));

    return 0;
}
