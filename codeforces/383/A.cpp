#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if (!n) {
        cout << 1 << endl;
        return 0;
    }
    
    n--;
    int ans;
    switch (n % 4) {
        case 0: ans = 8; break;
        case 1: ans = 4; break;
        case 2: ans = 2; break;
        case 3: ans = 6; break;
    }
    
    cout << ans << endl;
    
    return 0;
}
