#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    
    ll start = max(l1, l2);
    ll end = min(r1, r2);
    
    ll res;
    if (end - start >= 0) {
        res = end - start + 1;
        if (start <= k && k <= end) res--;
    } else {
        res = 0;
    }
    
    printf("%lld\n", res);
    
    return 0;
}
