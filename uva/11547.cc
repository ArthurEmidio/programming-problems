#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int res = abs((((((n * 567) / 9) + 7492) * 235) / 47) - 498);
        cout << static_cast<int>((res % 100) / 10) << endl;
    }
    
    return 0;
}
