#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    
    int occ[5] = {};
    for (int i = 0; i < s.size(); i += 2) {
        occ[s[i] - '0']++;
    }
    
    bool bef = false;
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < occ[i]; j++) {
            if (bef) cout << "+";
            cout << i;
            bef = true;
        }
    }
    cout << endl;
    
    return 0;
}