#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;

ll dp[1005];
int lim[255];

int n;
char s[1005];
int prep[1005];

int a2 = 1;

ll solve(int i)
{
    if (i == n) return 1;

    ll &ans = dp[i];
    if (ans != -1) return ans;

    ans = 0;
    for (int j = i, l = 1; j <= prep[i]; j++, l++) {
        a2 = max(a2, l);
        ans = (ans + solve(j + 1)) % MOD;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof dp);

    scanf("%d", &n);
    scanf("%s", s);
    getchar();

    for (int i = 'a'; i <= 'z'; i++) scanf("%d", &lim[i]);

    for (int i = 0; i < n; i++) {
        int j = i;
        bool occ[255] = {};
        for (int l = 1; j < n; j++, l++) {
            occ[s[j]] = true;
            bool stop = false;
            for (char c = 'a'; c <= 'z' && !stop; c++) if (occ[c] && lim[c] < l) stop = true;
            if (stop) break;
        }
        prep[i] = j-1;
    }

    int k = 0, cnt = 0;
    while (k < n) {
        k = prep[k] + 1;
        cnt++;
    }

    printf("%lld\n", (solve(0) % MOD));
    printf("%d\n", a2);
    printf("%d\n", cnt);

    return 0;
}
