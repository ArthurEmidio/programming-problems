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
        
        int maxV = 0;
        for (int j = 0; j < n; j++) {
            int v;
            cin >> v;
            maxV = max(maxV, v);
        }
        
        cout << "Case " << i + 1 << ": " << maxV << endl;
    }
    
    return 0;
}