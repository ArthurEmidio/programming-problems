#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n, c;
    scanf("%lld %lld", &n, &c);
    
    ll count = 1;
    ll last;
    scanf("%lld", &last);
    
    for (int i = 1; i < n; i++) {
        ll t;
        scanf("%lld", &t);
        
        if (t - last > c) count = 1;
        else count++;
        
        last = t;
    }
    
    printf("%lld\n", count);
    
    return 0;
}
