#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> primes;
vector<bool> isPrime;
unordered_set<ll> tprimes;

void sieve(int n)
{
    isPrime.assign(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (ll i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (ll j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
            primes.push_back(i);
        }
    }
}

void prep()
{
    for (ll p : primes) tprimes.insert(p*p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    sieve(1e6 + 5);
    prep();
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        printf("%s\n", tprimes.count(x) ? "YES" : "NO");
    }
    
    return 0;
}
