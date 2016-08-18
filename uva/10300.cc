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
        int f;
        cin >> f;
        
        int total = 0;
        for (int j = 0; j < f; j++) {
            int a, b, c;
            cin >> a >> b >> c;   
            total += a * c;
        }
        cout << total << endl;
    }
    
    return 0;   
}
