#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{    
    ll b, d, s;
    cin >> b >> d >> s;
    
    ll m = max(max(b, d), s);
    
    ll x = (m - 1) - (d);
    ll y = (m - 1) - (s);
    ll z = (m - 1) - (b);

    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (z < 0) z = 0;
    
    cout << (x + y + z) << endl;
    
    return 0;
}
