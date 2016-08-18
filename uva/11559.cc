#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    while (1) {
        int minCost = numeric_limits<int>::max();
        
        int n, b, h, w;
        cin >> n;
        
        if (cin.eof()) break;
                
        cin >> b >> h >> w;
        for (int i = 0; i < h; i++) {            
            int p;
            cin >> p;
            
            for (int j = 0; j < w; j++) {
                int a;
                cin >> a;
                                    
                if (a >= n) {
                    minCost = min(minCost, p * n);
                }
            }
        }
        
        if (minCost > b) {
            cout << "stay home" << endl;
        } else {
            cout << minCost << endl;
        }
    }
    
    return 0;
}