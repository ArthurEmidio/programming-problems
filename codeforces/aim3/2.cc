#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, a;
    scanf("%d %d", &n, &a);
        
    ll maxItem = numeric_limits<ll>::min();    
    ll prevMax = numeric_limits<ll>::min();
    
    ll minItem = numeric_limits<ll>::max();
    ll nextMin = numeric_limits<ll>::max();
    
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        
        if (x > maxItem) {
            prevMax = maxItem;
            maxItem = x;
        } else if (x > prevMax) {
            prevMax = x;
        }
        
        if (x < minItem) {
            nextMin = minItem;
            minItem = x;
        } else if (x < nextMin) {
            nextMin = x;
        }
    }
                    
    ll res;
    if (n == 1) {
        res = 0;
    } else if (n == 2) {
        res = min(abs(a - minItem), abs(maxItem - a));
    } else {
        if (a <= minItem) {
            res = abs(prevMax - a);
        } else if (a >= maxItem) {
            res = abs(a - nextMin);
        } else {
            ll extra1 = numeric_limits<ll>::max();
            ll extra2 = numeric_limits<ll>::max();
            
            if (a < nextMin) {
                extra1 = abs(maxItem - a);
            }
            if (a > prevMax) {
                extra2 = abs(a - minItem);
            }
            ll extraMin = min(extra1, extra2);
            
            ll opt1 = 2 * abs(maxItem - a) + abs(a - nextMin);                        
            ll opt2 = 2 * abs(a - minItem) + abs(prevMax - a);
            ll opt3 = 2 * abs(prevMax - a) + abs(a - minItem);
            ll opt4 = 2 * abs(a - nextMin) + abs(maxItem - a);
                    
            res = min(extraMin, min(min(opt1, opt2), min(opt3, opt4)));
        }
    }
    
    cout << res << endl;
    
    return 0;
}
