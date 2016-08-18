#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <map>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
     
    int prev = 1;   
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        
        if (a % 2 == 0) {
            cout << prev << endl;
            prev = prev == 1 ? 2 : 1;
        } else {
            int x = prev;
            prev = prev == 1 ? 2 : 1;
            cout << prev << endl;
            prev = x;
        }        
    }

    return 0;
}
