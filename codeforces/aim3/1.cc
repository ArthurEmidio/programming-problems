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
    
    int n, b, d;
    cin >> n >> b >> d;
    
    ll res = 0;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        
        if (a <= b) {
            tot += a;
            if (tot > d) {
                res++;
                tot = 0;
            }
        }
    }
    
    printf("%lld\n", res);
        
    return 0;
}
