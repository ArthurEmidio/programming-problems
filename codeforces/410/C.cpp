#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    int g = v[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, v[i]);
    }

    if (g > 1) {
        printf("YES\n0\n");
        return 0;
    }

    int ans = 0;
    for (int i = 0; i+1 < n; i++) {
        if (v[i] % 2 == 0 && v[i+1] % 2 == 0) continue;
        while (v[i] % 2 != 0 || (v[i+1] % 2 != 0 && (i+2 == n || v[i+2] % 2 == 0))) {
            int tmp = v[i];
            v[i] -= v[i+1];
            v[i+1] += tmp;
            ans++;
        }
    }

    printf("YES\n%d\n", ans);

    return 0;
}
