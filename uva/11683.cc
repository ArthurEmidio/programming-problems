#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <limits>

using namespace std;

int main()
{
    for (;;) {
        int a, c;
        char d;
        scanf("%d %d%c", &a, &c, &d);
        
        if (a == 0 || c == 0 || d == ' ') break;
                
        int h;
        cin >> h;
        
        int n = a - h;
        int prevH = h;
        
        for (int i = 1; i < c; i++) {
            cin >> h;
            if (h < prevH) n += (prevH - h);
            prevH = h;
        }
        
        cout << n << endl;
    }
    
    return 0;
}
