#include <bits/stdc++.h>

using namespace std;

int main()
{
    int F, I, T;
    cin >> F >> I >> T;
    
    int votes[15] = {};
    for (int i = 0; i < F; i++) {
        string v;
        cin >> v;
        for (int j = 0; j < I; j++) votes[j] += (v[j] == 'Y');
    }
    
    int ans = 0;
    for (int i = 0; i < I; i++) {
        if (votes[i] >= T) ans++;
    }
    
    cout << ans << endl;
    
    return 0; 
}