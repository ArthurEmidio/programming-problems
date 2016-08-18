#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <limits>

using namespace std;

int main()
{
    for (;;) {
        int l;
        cin >> l;
        if (l == 0) break;
        
        int r = numeric_limits<int>::max();
        int d = numeric_limits<int>::max();
        int minDist = numeric_limits<int>::max();
        
        for (int i = 0; i < l; i++) {
            char c;
            cin >> c;
            
            int dist;
            switch (c) {
                case 'R':
                    dist = abs(d - i);
                    r = i;
                    break;
                case 'D':
                    dist = abs(r - i);
                    d = i;
                    break;
                case 'Z':
                    dist = 0;
                    break;
                default:
                    dist = minDist;
                    break;
            }
            minDist = min(dist, minDist);
        }
        cout << minDist << endl;
    }
    
    return 0;
}

