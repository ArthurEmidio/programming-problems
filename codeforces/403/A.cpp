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

    int n;
    scanf("%d", &n);

    vector<int> v(n + 5, 0);
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < 2*n; i++) {
        int x;
        scanf("%d", &x);
        v[x]++;
        if (v[x] == 1) curr++;
        else curr--;
        ans = max(ans, curr);
    }

    printf("%d\n", ans);

    return 0;
}
