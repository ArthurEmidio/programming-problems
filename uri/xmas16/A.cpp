#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<bool> isPrime;
vector<ll> primes;

void sieve(ll n)
{
    isPrime.assign(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (ll i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (ll j = i*i; j <= n; j+=i) {
                isPrime[j] = false;
            }
            primes.push_back(i);
        }
    }
}

bool prime(ll n)
{
    if (n < 100001) return isPrime[n];
    for (ll i : primes) {
        if (n % i == 0) return false;
    }
    return true;
}

ll solve(ll n)
{
    if (prime(n)) return n-1;
    else if (n % 2 == 0) return n-2;
    else return prime(n-2) ? n-2 : n-3;
}

int main()
{
    sieve(100001);
           
    ll n;
    while (cin >> n) {
        printf("%lld\n", solve(n));
    }
    
    return 0;
}
