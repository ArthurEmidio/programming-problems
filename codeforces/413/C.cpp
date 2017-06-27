#include <bits/stdc++.h>

using namespace std;

int f(const vector<pair<int, int>> &items, const vector<int> &maxItemBeauty, int cash, int maxOther)
{
    int ans = 0;
    for (auto it = items.begin(); it != items.end(); it++) {
        int maxBeauty = maxOther;

        int cost = it->first;
        int beauty = it->second;

        if (it != items.begin()) {
            auto it2 = upper_bound(items.begin(), it, make_pair(cash - cost, INT_MAX));
            if (it2 != items.begin()) {
                int idx = prev(it2) - items.begin();
                maxBeauty = max(maxBeauty, maxItemBeauty[idx]);
            }
        }
        if (maxBeauty) ans = max(ans, maxBeauty + beauty);
    }

    return ans;
}

int main()
{
    int n, c, d;
    scanf("%d %d %d", &n, &c, &d);

    int mc = 0;
    int md = 0;

    vector<pair<int, int>> coins, diamonds;
    for (int i = 0; i < n; i++) {
        int b, p;
        char t;
        scanf("%d %d %c", &b, &p, &t);
        if (t == 'C' && p <= c) {
            mc = max(mc, b);
            coins.push_back({p, b});
        } else if (t == 'D' && p <= d) {
            md = max(md, b);
            diamonds.push_back({p, b});
        }
    }

    sort(coins.begin(), coins.end());
    sort(diamonds.begin(), diamonds.end());

    vector<int> coinMaxBeauty(coins.size()), diamMaxBeauty(diamonds.size());
    for (int i = 0; i < coins.size(); i++) {
        coinMaxBeauty[i] = i ? max(coinMaxBeauty[i - 1], coins[i].second) : coins[i].second;
    }
    for (int i = 0; i < diamonds.size(); i++) {
        diamMaxBeauty[i] = i ? max(diamMaxBeauty[i - 1], diamonds[i].second) : diamonds[i].second;
    }

    int ans = max(f(coins, coinMaxBeauty, c, md), f(diamonds, diamMaxBeauty, d, mc));
    printf("%d\n", ans);

    return 0;
}
