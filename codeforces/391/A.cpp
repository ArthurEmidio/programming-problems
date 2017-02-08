#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    vector<int> v(255, 0);
    for (char c : s) v[c]++;
        
    v['u'] /= 2;
    v['a'] /= 2;
    
    int ans = INT_MAX;
    string bulb = "Bulbasaur";
    for (char c : bulb) ans = min(ans, v[c]);
    cout << ans << endl;
        
    return 0;
}