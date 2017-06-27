#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, f;
    cin >> n >> f;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        return min(p1.first * 2, p1.second) - min(p1.first, p1.second) >
               min(p2.first * 2, p2.second) - min(p2.first, p2.second);
    });

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < f) v[i].first *= 2;
        ans += min(v[i].first, v[i].second);
    }

    cout << ans << endl;

    return 0;
}
