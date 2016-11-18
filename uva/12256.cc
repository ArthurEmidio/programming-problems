#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int tc = 1;
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;
        
        ll n1 = 1;
        ll n2 = 1;
        ll n3 = 1;
        ll n4 = 3;
        
        for (int i = 5; i <= n; i++) {
            ll tmp = n2 + n3 + n4;
            n1 = n2;
            n2 = n3;
            n3 = n4;
            n4 = tmp;
        }
        
        printf("Case %d: %lld\n", tc++, n4);
    }
    
    return 0;
}
