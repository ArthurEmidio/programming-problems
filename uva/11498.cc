#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    while (1) {
        int k;
        cin >> k;
        if (k == 0) break;
            
        int m, n;
        cin >> m >> n;
    
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            
            if (x == m || y == n) {
                cout << "divisa";
            } else {
                if (x < m) {
                    if (y < n) {
                        cout << "SO";
                    } else {
                        cout << "NO";
                    }
                } else {
                    if (y < n) {
                        cout << "SE";
                    } else {
                        cout << "NE";
                    }
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}
