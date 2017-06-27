#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<pair<int, pair<int, int>>> shirts(n);
    for (int i = 0; i < n; i++) scanf("%d", &shirts[i].first);
    for (int i = 0; i < n; i++) scanf("%d", &shirts[i].second.first);
    for (int i = 0; i < n; i++) scanf("%d", &shirts[i].second.second);

    set<int> prices[4];
    for (const pair<int, pair<int, int>> &shirt : shirts) {
        prices[shirt.second.first].insert(shirt.first);
        prices[shirt.second.second].insert(shirt.first);
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        int c;
        scanf("%d", &c);
        if (prices[c].empty()) {
            printf("-1 ");
        } else {
            int ans = *prices[c].begin();
            printf("%d ", ans);
            for (int i = 1; i <= 3; i++) prices[i].erase(ans);
        }
    }
    printf("\n");

    return 0;
}
