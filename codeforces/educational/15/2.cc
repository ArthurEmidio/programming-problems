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
    
    map<ll, ll> v;
    vector<ll> inp;
    
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        inp.push_back(a);
        
        if (v.count(a) == 0) v[a] = 0;
        v[a]++;
    }
    
    ll c = 0;
    for (ll i = 0; i < n; i++) {
        ll a1 = inp[i];
        
        for (ll j = 0; j <= 32; j++) {
            ll a2 = pow(2, j) - a1;
            if (v.count(a2) > 0) {
                if (a2 == a1) {
                    c += v[a2] - 1;
                } else {
                    c+= v[a2];
                }               
            }         
        }
        
        if (v[a1] == 1) {
            v.erase(a1);
        } else {
            v[a1]--;
        }
    }
    
    cout << c << endl;
    
    return 0;
}