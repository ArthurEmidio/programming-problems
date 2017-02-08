#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    bool invalid = false;
    pair<int, int> p(0,0);
    for (int i = 0; i < n; i++) {
        int t;
        string d;
        cin >> t >> d;
        
        if (invalid) continue;
        
        if (d == "South" && p.ss - t < -20000) invalid = true;
        else if (d == "North" && p.ss + t > 0) invalid = true;
        
        if ((!p.ss && d != "South") || (p.ss == -20000 && d != "North")) {
            invalid = true;
        }
        
        t = t % 40000;
        
        if (d == "North") p.ss += t;
        else if (d == "South") p.ss -= t;
        else if (d == "West") p.ff -= t;
        else p.ff += t;
    }
    
    if (!invalid && !p.ss) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
