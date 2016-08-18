#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    
    int tot = 0;
    for (int i = 0; i < t; i++) {
        string op;
        cin >> op;
        
        if (op == "donate") {
            int v;
            cin >> v;
            tot += v;
        } else {
            cout << tot << endl;
        }
    }
    
    return 0;
}
