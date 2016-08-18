#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int l, w, h;
        cin >> l >> w >> h;
        
        cout << "Case " << i + 1 << ": ";
        if (l > 20 || w > 20 || h > 20) {
            cout << "bad";
        } else {
            cout << "good";
        }
        cout << endl;
    }
    
    return 0;
}
