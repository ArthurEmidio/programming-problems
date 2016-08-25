#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    
    vector<ll> numbers(n);
    for (ll i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    
    ll res;
    if (numbers.size() == 1) {
        res = numbers[0];
    } else if (numbers.size() % 2 == 0) {
        res = numbers[(numbers.size() / 2) - 1];
    } else {
        res = numbers[(numbers.size() / 2)];
    }
    
    cout << res << endl;
    
    // ll prevX;
 //    cin >> prevX;
 //
 //    ll curr = -1;
 //    ll minDist = std::numeric_limits<ll>::max();
 //
 //    for (ll i = 1; i < n; i++) {
 //        ll x;
 //        cin >> x;
 //
 //        ll currDist = x - prevX;
 //        if (currDist < minDist) {
 //            curr = x;
 //            minDist = currDist;
 //        }
 //
 //        prevX = x;
 //    }
 //
 //    cout << curr << endl;
    
    return 0;
}
