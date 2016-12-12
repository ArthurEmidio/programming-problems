#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> moods(n);
    for (int i = 0; i < n; i++) {
        cin >> moods[i];
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        
        int curr = ans;
        for (int j = l - 1; j < r; j++) curr += moods[j];        
        ans = max(ans, curr);
    }
    
    cout << ans << endl;
    
    return 0;
}