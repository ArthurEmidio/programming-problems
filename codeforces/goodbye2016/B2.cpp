#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int y = 0;
    bool ans = true;
    while (n--) {
        int q;
        string d;
        cin >> q >> d;
        
        if ((y == 0 && d != "South") || (y == -20000 && d != "North")) ans = false;
        if (d == "South" || d == "North") {
            y += (d == "South") ? -q : q;
            if (y > 0 || y < -20000) ans = false;
        }
    }
    
    if (y != 0) ans = false;
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}