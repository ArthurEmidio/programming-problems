#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    while (1) {
        int b, n;
        cin >> b >> n;
        
        if (b == 0 && n == 0) break;
        
        vector<int> balances(b);
        for (int i = 0; i < b; i++) {
            cin >> balances[i];
        }
        
        for (int i = 0; i < n; i++) {
            int d, c, v;
            cin >> d >> c >> v;
            d--;
            c--;
            
            balances[c] += v;
            balances[d] -= v;            
        }
        
        bool result = true;
        for (int balance : balances) {
            if (balance < 0) {
                result = false;
                break;
            }
        }
        cout << (result ? "S" : "N") << endl;
    }
}