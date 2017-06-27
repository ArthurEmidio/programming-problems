#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        if (b < x && x < c) ans++;
    }

    cout << ans << endl;

    return 0;
}
