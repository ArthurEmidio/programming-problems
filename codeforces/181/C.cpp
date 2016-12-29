#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define MOD 1000000007

ll fact[1000006];
ll C[1000006] = {};
char str[10];
char A, B;

bool isGood()
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != A && str[i] != B) return false;
    }
    return true;
}

ll exp(ll a, ll b)
{        
    ll x = 1, y = a;
    while (b) {
        if (b % 2) x = (x*y) % MOD;
        y = (y*y) % MOD;
        b /= 2;
    }

    return x;
}

ll f(ll n, ll r)
{
    if (r == 0) return 1;
    if (r == 1) return n;
    if (C[r]) return C[r];
    return C[r] = (((fact[n] * exp(fact[r], MOD-2)) % MOD) * exp(fact[n-r], MOD-2)) % MOD;
}

int main()
{    
    fact[1] = 1;
    for (int i = 2; i < 1000006; i++) fact[i] = (fact[i-1] * i) % MOD;

    ll a, b, n;
    scanf("%lld %lld %lld", &a, &b, &n);
    if (a < b) swap(a,b);

    A = a + '0';
    B = b + '0';

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ll x = i * a + (n-i) * b;
        sprintf(str, "%lld", x);
        if (isGood()) {
            ans = (ans + f(n, min(i,n-i))) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}