#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
        
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = 1, j = i;
        while (p[j] != -1) tmp++, j = p[j]-1;
        ans = max(ans, tmp);
    }
    
    cout << ans << endl;
    
    return 0;
}