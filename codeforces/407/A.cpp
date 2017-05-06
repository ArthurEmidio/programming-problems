#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> ws(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ws[i]);
    }

    int ans = 0;
    for (int i = 0; i < n;) {
        if (ws[i] <= 0) {
            i++;
            continue;
        }

        if (ws[i] <= k) {
            ans++;
            if (i+1 < n) ws[i+1] -= k;
            i++;
        } else if (ws[i] < 2*k) {
            ans++;
            i++;
        } else {
            ans += ws[i] / (2*k);
            ws[i] = ws[i] % (2*k);
        }
    }

    printf("%d\n", ans);

    return 0;
}
