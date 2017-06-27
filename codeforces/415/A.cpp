#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int S = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        S += x;
    }

    int ans = ceil(2 * (n * (k - 0.5) - S));
    printf("%d\n", max(0, ans));

    return 0;
}
