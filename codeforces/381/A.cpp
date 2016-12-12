#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define oo INT_MAX

int main()
{
    ll n;
    cin >> n >> a >> b >> c;
    
    ll ans = oo;
    int rem = 4 - (n % 4);
    if (rem == 1) {
        // 1, 2+3, 3+3+3
        ans = min(ans, a);
        ans = min(ans, b + c);
        ans = min(ans, c * 3);
    } else if (rem == 2) {
        // 1+1, 2, 3+3
        ans = min(ans, a * 2);
        ans = min(ans, b);
        ans = min(ans, c * 2);
    } else if (rem == 3) {
        // 1+1+1, 1+2, 3
        ans = min(ans, a * 3);
        ans = min(ans, a + b);
        ans = min(ans, c);
    } else {
        ans = 0;
    }
    
    cout << ans << endl;
    
    return 0;
}
