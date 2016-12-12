#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        char ac = tolower(a[i]);
        char bc = tolower(b[i]);
        
        if (ac < bc) {
            ans = -1;
            break;
        } else if (ac > bc) {
            ans = 1;
            break;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}