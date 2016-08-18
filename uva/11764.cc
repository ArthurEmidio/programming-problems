#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int highJumps = 0;
        int lowJumps = 0;
        int prevH;
        cin >> prevH;
        
        for (int j = 1; j < n; j++) {
            int h;
            cin >> h;
            if (h < prevH) {
                lowJumps++;
            } else if (h > prevH) {
                highJumps++;
            }
            prevH = h;
        }
        
        cout << "Case " << i + 1 << ": " << highJumps << " " << lowJumps << endl;
    }
    
    return 0;
}