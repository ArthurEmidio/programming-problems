#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll t;
    scanf("%lld", &t);
    
    while (t--) {
        ll n;
        scanf("%lld", &n);
        
        ll ropes = (n & 1) == 0 ? (n/2) : ((n/2) + 1);

        ll begin = 1;
        ll end = n;
        while (end > begin) {
            ll middle = (begin + end) / 2;
            ll res = 3 * middle + 1;
            if (res > n) {
                end = middle - 1;
            } else {
                begin = middle + 1;
            }
        }
                
        if (3*end + 1 > n) --end;                
        ropes += (n & 1) == 0 ? ((n-end)/2) : ((n-end+1)/2);
        
        printf("%lld\n", ropes);
    }
    
    return 0;
}
