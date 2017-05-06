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

char s[100005];
ll root;

ll f(ll u, ll st, stack<ll> &hist)
{
    ll v = root;
    while (u != v) {
        hist.push(v);
        if (u > v) v += st;
        else v -= st;
        st /= 2;
    }

    return st;
}

int main()
{
    ios_base::sync_with_stdio(false);

    ll n, q;
    scanf("%lld %lld", &n, &q);

    root = (n+1) / 2;

    while (q--) {
        ll u;
        scanf("%lld", &u);
        getchar();
        scanf("%s", s);

        stack<ll> hist;
        ll walk = f(u, root/2, hist);
        ll curr = u;

        ll xxx = strlen(s);
        for (int i = 0; i < xxx; i++) {
            char c = s[i];
            if (c == 'U') {
                if (!hist.empty()) {
                    if (walk) walk *= 2;
                    else walk = 1;
                    curr = hist.top(); hist.pop();
                }
            } else {
                if (walk) {
                    hist.push(curr);
                    if (c == 'L') curr -= walk;
                    else curr += walk;
                    walk /= 2;
                }
            }
        }

        printf("%lld\n", curr);
    }

    return 0;
}
