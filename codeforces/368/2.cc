#include <iostream>
#include <limits>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define ll long long
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<map<ll, ll>> roads(n);        
    for (int i = 0; i < m; i++) {
        ll u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;
        
        map<ll, ll> &neighbors = roads[u];
        map<ll, ll> &neighborsRev = roads[v];
        
        ll dist = neighbors.count(v) > 0 ? min(l, neighbors[v]) : l;
        neighbors[v] = dist;
        neighborsRev[u] = dist;
    }
    
    set<ll> storages;
    for (int i = 0; i < k; i++) {
        ll a;
        cin >> a;
        storages.insert(a - 1);
    }
    
    ll minDist = numeric_limits<ll>::max();
    bool entered = false;
    for (ll storageIdx : storages) {
        map<ll, ll> &neighbors = roads[storageIdx];
        for (const pair<ll, ll> &neighbor : neighbors) {
            if (storages.count(neighbor.first) == 0) {
                minDist = min(neighbor.second, minDist);
                entered = true;
            } else {
                map<ll, ll> &other = roads[neighbor.first];
                other.erase(storageIdx);
            }
        }
    }
    
    if (!entered) {
        minDist = -1;
    }
    
    cout << minDist << endl;

    return 0;
}
