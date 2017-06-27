#include <bits/stdc++.h>

using namespace std;

int f(int n, int t, int k, int d)
{
    int currT = 0;
    while (n > 0) {
        if (currT >= d && currT % d == 0) n -= k;
        if (currT % t == 0) n -= k;
        currT++;
    }
    return currT-1;
}

int main()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int ans1 = f(n, t, k, INT_MAX);
    int ans2 = f(n, t, k, d);

    printf("%s\n", ans1 <= ans2 ? "NO" : "YES");

    return 0;
}
