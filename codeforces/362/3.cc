#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    map<pair<ll, ll>, ll> intersections;
    vector<ll> totFees;
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int ev;
        cin >> ev;
        
        if (ev == 1) {
            ll v, u, w;
            cin >> v >> u >> w;
            
            while (v != u) {
                if (v > u) {
                    ll vParent = v / 2;
                    auto p1 = make_pair(v, vParent);
                    
                    if (intersections.count(p1) == 0) {
                        intersections[p1] = 0;
                    }
                    
                    intersections[p1] += w;
                    
                    v /= 2;
                } else {
                    ll uParent = u / 2;
                    auto p1 = make_pair(u, uParent);
                    
                    if (intersections.count(p1) == 0) {
                        intersections[p1] = 0;
                    }
                    
                    intersections[p1] += w;
                    
                    u /= 2;
                }
            }
        } else {
            ll fees = 0;
            
            ll v, u;
            cin >> v >> u;
            
            while (v != u) {
                if (v > u) {
                    ll vParent = v / 2;
                    auto p1 = make_pair(v, vParent);
                    
                    if (intersections.count(p1) > 0) {
                        fees += intersections[p1];
                    }
                    
                    v /= 2;
                } else {
                    ll uParent = u / 2;
                    auto p1 = make_pair(u, uParent);
                    
                    if (intersections.count(p1) > 0) {
                        fees += intersections[p1];
                    }
                    
                    u /= 2;
                }
            }
            
            totFees.push_back(fees);
        }
    }
    
    for (ll fee : totFees) {
        cout << fee << endl;
    }
    cout << endl;
    
    return 0;
}
