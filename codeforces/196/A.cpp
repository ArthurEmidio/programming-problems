#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> puzzles(m);
    for (int i = 0; i < m; i++) {
        cin >> puzzles[i];
    }
    
    sort(puzzles.begin(), puzzles.end());
    
    int i = 0, j = n-1;
    int ans = INT_MAX;
    while (j < m) {
        ans = min(ans, puzzles[j] - puzzles[i]);
        i++, j++;
    }
    
    cout << ans << endl;
    
    return 0;
}