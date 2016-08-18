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
    
    bool hate = true;
    for (int i = 0; i < n - 1; i++) {
        if (hate) {
            cout << "I hate that ";
        } else {
            cout << "I love that ";
        }
        hate = !hate;
    }
    
    if (hate) {
        cout << "I hate it";
    } else {
        cout << "I love it";
    }
    
    cout << endl;

    return 0;
}
