#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1) n++;
    int ans = ((n - 2) / 2);
    ans += n % 2;
    cout << ans << endl;

    // int i = 1, j = n, ans = 0;
    // bool even = true;
    // while (i < j) {
    //     if (even) i++;
    //     else j--, ans++;
    //     even = !even;
    // }
    // cout << ans << endl;

    return 0;
}
