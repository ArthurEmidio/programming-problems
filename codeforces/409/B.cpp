#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x, y;
    cin >> x >> y;

    string ans;
    for (int i = 0; i < x.size(); i++) {
        char c = y[i];
        if (c > x[i]) {
            ans.clear();
            break;
        }

        ans += min(c, x[i]);
    }

    if (ans.empty()) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
