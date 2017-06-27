#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);

    int v[200005] = {};
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        v[l]++;
        v[r + 1]--;
    }

    int prev = 0;
    int look[200005] = {};
    for (int i = 1; i <= 200000; i++) {
        int q = prev + v[i];
        look[i] = look[i - 1] + (q >= k);
        prev = q;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", look[r] - look[l - 1]);
    }

    return 0;
}
