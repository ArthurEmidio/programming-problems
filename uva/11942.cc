#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    cout << "Lumberjacks:" << endl;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        
        int prevH, h;
        cin >> prevH >> h;
        bool ascending = prevH < h;
        
        bool ordered = true;
        for (int j = 2; j < 10; j++) {
            int h;
            cin >> h;
            if ((ascending && h < prevH) || (!ascending && h > prevH)) {
                ordered = false;
            }
            prevH = h;
        }
        
        cout << (ordered ? "Ordered" : "Unordered") << endl;
    }
    
    return 0;
}