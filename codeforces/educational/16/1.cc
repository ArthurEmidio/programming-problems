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
    
    char c;
    int d;
    
    cin >> c >> d;
    
    int res = 0;
    
    bool left = true;
    bool right = true;
    if (c == 'a') {
        left = false;
    } else if (c == 'h') {
        right = false;
    }
    
    bool bottom = true;
    bool top = true;
    if (d == 1) {
        bottom = false;
    } else if (d == 8) {
        top = false;
    }
    
    if (top) {
        res++;
        if (left) res++;
        if (right) res++;
    }
    
    if (bottom) {
        res++;
        if (left) res++;
        if (right) res++;
    }
    
    if (left) res++;
    if (right) res++;
    
    cout << res << endl;
        
    return 0;
}
