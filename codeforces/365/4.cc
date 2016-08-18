#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <map>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    
    vector<map<int, int>> entries(n);    
    map<int, int> currMap;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (currMap.count(a) == 0) currMap[a] = 0;
        currMap[a]++;
        entries[i] = currMap;
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        
        map<int, int> lm;
        if (l > 0) lm = entries[l - 1];
        
        map<int, int> rm = entries[r];

        ll res = 0;
        for (pair<int, int> x : rm) {
            int key = x.first;
            int occ = x.second;

            if (lm.count(key) != 0) {
                occ -= lm[key];
            }

            if (occ != 0) {
                if (occ % 2 == 0) {
                    res ^= key;
                }
            }
        }

       cout << res << endl;
    }

    return 0;
}
