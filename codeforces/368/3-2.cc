#include <iostream>
#include <vector>
#include <set>
#include <map>

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

#define ll long long
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll a, b, c;
    cin >> a;    
    bool valid = true;
    if (a & 1) {
        b = (a * a - 1) / 2;
        c = b + 1;        
    } else {
        b = (a / 2) * (a / 2) - 1;
        c = b + 2;
    }
    
    if (b > 0 && c > 0) {
        cout << b << " " << c << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}