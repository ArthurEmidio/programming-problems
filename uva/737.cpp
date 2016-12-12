#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX

typedef pair<int, int> ii;

int main()
{
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;
        
        ii X(-oo, oo), Y(-oo, oo), Z(-oo, oo);
        for (int i = 0; i < n; i++) {
            int x, y, z, l;
            cin >> x >> y >> z >> l;
            
            X.first = max(X.first, x);
            X.second = min(X.second, x + l);
            
            Y.first = max(Y.first, y);
            Y.second = min(Y.second, y + l);
            
            Z.first = max(Z.first, z);
            Z.second = min(Z.second, z + l);
        }
        
        int ans = 0;
        if (X.first < X.second && Y.first < Y.second && Z.first < Z.second) {
            ans = (X.second - X.first) * (Y.second - Y.first) * (Z.second - Z.first);
        }
        cout << ans << endl;
    }
    
    return 0;
}