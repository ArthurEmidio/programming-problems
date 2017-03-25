#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ll t, s, x;
    cin >> t >> s >> x;
    
    if ((s > 1 && t + 1 == x) || t > x) {
        printf("NO\n");
    } else {
        ll res = (x - t) % s;
        printf("%s\n", (res == 0 || res == 1) ? "YES" : "NO");
    }
    
    return 0;
}
