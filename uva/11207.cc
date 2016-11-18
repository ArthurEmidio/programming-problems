#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;
        
        double greatestSide = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            double b, h;
            cin >> b >> h;
            
            double ratio = max(b, h) / min(b, h);
            double side = ratio >= 4 ? min(b, h) : max(min(b,h)/2, max(b,h)/4);
            
            if (side > greatestSide) {
                greatestSide = side;
                ans = i + 1;
            }            
        }
        
        cout << ans << endl;
    }
    
    return 0;
}