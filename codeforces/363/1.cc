#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    
    vector<char> input(n);
    
    for (ll i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    ll minDist = numeric_limits<ll>::max();
    ll maxRight = -1;
    ll maxLeft = -1;
    
    for (ll i = 0; i < n; i++) {
        ll p;
        cin >> p;
        
        if (input[i] == 'L') {
            ll dist = (maxRight != -1 && p > maxRight) ? (p - maxRight) : numeric_limits<ll>::max();
            minDist = min(dist, minDist);
            maxLeft = max(p, maxLeft);
        } else {
            ll dist = (maxLeft != -1 && maxLeft > p) ? (p - maxLeft) : numeric_limits<ll>::max();
            minDist = min(dist, minDist);
            maxRight = max(p, maxRight);
        }
    }
    
    if (minDist == numeric_limits<ll>::max()) {
        cout << -1 << endl;
    } else {
        cout << (minDist / 2) << endl;
    }
    
    return 0;
}
