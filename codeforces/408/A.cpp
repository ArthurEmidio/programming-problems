#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> prices(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (prices[i] > 0 && prices[i] <= k) ans = min(ans, abs(i - m));
    }

    cout << ans*10 << endl;

    return 0;
}
