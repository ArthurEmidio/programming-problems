#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    while (1) {
        int h, u, d, f;
        cin >> h;
        if (h == 0) break;
        cin >> u >> d >> f;
        
        double currHeight = 0;
        int day = 0;
        double decrease = u * (f / 100.0);
        double increase = u;
        
        while (currHeight < h && currHeight >= 0) {
            if (increase > 0) {
                currHeight += increase;
            }
            
            if (currHeight > h) {    
                day++;
                break;
            }
            
            currHeight -= d;
            increase -= decrease;
            day++;
        }
        
        if (currHeight > h) {
            cout << "success";
        } else {
            cout << "failure";
        }
        cout << " on day " << day << endl;
    }
    
    return 0;
}