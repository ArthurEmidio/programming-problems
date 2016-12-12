#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int ans = 1;
    int prev;
    cin >> prev;
    
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        
        if (x != prev) {
            prev = x;
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}