#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        
        if (a == b) {
            cout << "=" << endl;
        } else if (a < b) {
            cout << "<" << endl;
        } else {
            cout << ">" << endl;
        }
    }
    
    return 0;
}
