#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793
typedef long long ll;

int main()
{
    for (;;) {
        ll l, w, h, theta;
        cin >> l;
        if (cin.eof()) break;
        cin >> w >> h >> theta;
        
        double angle = theta * PI / 180;
        double totVol = h * l * w;
        
        double emptyVol;
        if (angle > atan2(h, l)) { // if part of the packet's base doesn't have milk        
            double base = h / tan(angle);
            emptyVol = totVol - ((base * h * w) / 2);
        } else {
            double height = l * tan(angle);
            emptyVol = (height * l * w) / 2;
        }
        
        printf("%.3f mL\n", totVol - emptyVol);
    }
    
    return 0;
}
