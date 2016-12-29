#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    
    ll x = 0, y = numeric_limits<int>::max();
    
    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            ll j = n / i;
                        
            if (abs(j-i) < abs(y-x)) {
                x = min(i,j);
                y = max(i,j);
            }
        }
    }
    
    printf("%lld %lld\n", x, y);
    
    return 0;
}
