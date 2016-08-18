#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    
    int curr = 1;
    int m = curr;
    
    int l; 
    cin >> l;
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        if (a > l) {
            curr++;
            m = max(curr, m);
        } else {
            curr = 1;
        }
        l = a;
    }
    
    cout << m << endl;
    
    return 0;
}