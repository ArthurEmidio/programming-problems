#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int a;
    cin >> a;
    
    ll ans = 1;
    while (a--) {
        ans *= 2;
        if (ans == 8192) ans -= 100;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}