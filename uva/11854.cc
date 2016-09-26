#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    for (;;) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
                
        ll ms = max(max(a, b), c);
        if (ms == a) {
            swap(a, c);
        } else if (ms == b) {
            swap(b, c);
        }
        
        printf("%s\n", (a*a + b*b == c*c) ? "right" : "wrong");
    }
    
    return 0;
}
