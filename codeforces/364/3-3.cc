#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    
    vector<char> seq;
    set<char> pokemons;
    
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        seq.push_back(c);
        pokemons.insert(c);
    }
    
    int lp = 0;
    int rp = 1;
    int dist = (pokemons.size() == 1) ? 1 : numeric_limits<int>::max();
    
    map<char, int> seen;
    seen[seq[lp]] = 1;
    
    while (rp < n) {
        while (lp < rp - 1 && seen[seq[lp]] > 1) {
            seen[seq[lp]]--;
            lp++;
        }
    
        if (seq[lp] != seq[rp]) {
            char lc = seq[lp];
            char rc = seq[rp];
            
            if (seen.count(rc) == 0) seen[rc] = 0;
            seen[rc]++;
                        
            if (seen.size() == pokemons.size()) {
                dist = min(rp - lp + 1, dist);
                
                if (seen[lc] == 1) {
                    seen.erase(lc);
                } else {
                    seen[lc]--;
                }
                lp++;
            }
        } else {
            lp++;
        }
        
        rp++;
    }
    
    cout << dist << endl;
        
    return 0;
}
