#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n, k, a, b;
    scanf("%lld %lld %lld %lld", &n, &k, &a, &b);
    
    ll va = max(a,b);
    ll vb = min(a,b);
    char ca = a > b ? 'G' : 'B';
    char cb = a <= b ? 'G' : 'B';
    
    if (va > k*(vb+1)) {
        printf("NO\n");
    } else {
        while (vb+1 > 0) {
            ll lim = k;
            while (lim && va-vb > 0) {
                printf("%c", ca);
                lim--, va--;
            }
            
            if (vb > 0) printf("%c", cb);
            vb--;
        }
        printf("\n");
    }
    
    return 0;
}
