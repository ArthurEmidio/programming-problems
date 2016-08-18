#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        
        int w1 = abs(b - a);
        int w2 = min(a, b) + (99 - max(a, b)) + 1;
        
        cout << min(w1, w2) << endl;
    }
    
    return 0;
}
