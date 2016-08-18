#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int minDist = numeric_limits<int>::max();
        int maxDist = numeric_limits<int>::min();
        for (int j = 0; j < n; j++) {
            int st;
            cin >> st;
            minDist = min(minDist, st);
            maxDist = max(maxDist, st);
        }
        
        cout << 2 * (maxDist - minDist) << endl;
    }
    
    return 0;
}