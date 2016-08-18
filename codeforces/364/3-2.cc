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
    
    map<char, int> pokemons;
    vector<char> seq;
    
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        
        seq.push_back(c);
        
        if (pokemons.count(c) == 0) {
            pokemons[c] = 1;
        } else {
            pokemons[c]++;
        }
    }
    
    int lp = 0;
    int rp = n - 1;
    
    while (pokemons[seq[rp]] > 1) {
        pokemons[seq[rp]]--;
        rp--;
    }
    
    while (pokemons[seq[lp]] > 1) {
        pokemons[seq[lp]]--;
        lp++;
    }
    
    cout << rp - lp + 1 << endl;
        
    return 0;
}
