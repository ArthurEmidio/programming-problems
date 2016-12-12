#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    sort(v.begin(), v.end());
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(i - v[i-1]);
    }
    
    cout << ans << endl;
    
    return 0;
}