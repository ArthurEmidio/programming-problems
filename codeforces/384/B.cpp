#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

ll f(ll n, ll k)
{
    ll x = pow(2, n) - 1;
    if (x/2 == k-1) {
        return n;
    } else {
        return f(n-1, (k > x/2) ? (k - x/2 - 1) : k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    
    if (k % 2 == 1) {
        cout << 1 << endl;
    } else {
        cout << f(n,k) << endl;
    }
        
    return 0;
}
