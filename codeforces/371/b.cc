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
    scanf("%lld", &n);
    
    ll maxN = 0;
    ll minN = numeric_limits<ll>::max();
    
    vector<ll> numbers(n);
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &numbers[i]);
        maxN = max(maxN, numbers[i]);
        minN = min(minN, numbers[i]);
    }
    
    ll avg = (maxN + minN) / 2;
    ll x1 = maxN - minN; // reach maxN or minN
    ll x2 = maxN - avg;  // reach avg
    
    ll succX1 = 0;
    ll succX2 = 0;
    
    for (ll number : numbers) {
        if (number + x1 == maxN || number - x1 == minN || number == maxN || number == minN) {
            succX1++;
        }
        
        if (number + x2 == avg || number - x2 == avg || number == avg) {
            succX2++;
        }
    }
    
    if (succX1 == n || succX2 == n) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
