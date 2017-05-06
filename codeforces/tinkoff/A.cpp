#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v(n);
    int mi = INT_MAX;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        mi = min(mi, v[i]);
    }

    long long ans = 0;
    for (int x : v) {
        if ((x - mi) % k != 0) {
            printf("-1\n");
            return 0;
        }

        ans += (x - mi) / k;
    }

    printf("%lld\n", ans);

    return 0;
}
