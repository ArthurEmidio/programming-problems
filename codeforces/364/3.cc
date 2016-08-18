#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#define ll long long

set<char> pokemons;

bool catchedThemAll(const string &s)
{
    set<char> got;
    
    for (char c : s) {
        got.insert(c);
    }
    
    return got.size() == pokemons.size();
}

int main()
{
    int n;
    cin >> n;
        
    string s;
    for (int i = 0; i < n; i++) {
        char p;
        cin >> p;
        s.push_back(p);
        pokemons.insert(p);
    }
    
    int pn = pokemons.size();
    int j = 0;    
    int res = 0;    
    while (!res) {
        for (int i = 0; i <= s.size() - (pn + j); i++) {
            string x = s.substr(i, pn + j);
            if (catchedThemAll(x)) {
                res = x.size();
                break;
            }
        }
        j++;
    }
    
    cout << res << endl;
    
    return 0;
}
