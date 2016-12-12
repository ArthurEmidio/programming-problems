#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v;

ll rsq(int l, int r)
{
    return v[r+1] - v[l];
}

int main()
{
    int n, k;
    cin >> n >> k;
    k--;
    
    v.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        v[i] = v[i-1] + h;
    }
        
    int ans = 1;
    ll best = numeric_limits<ll>::max();
    for (int i = 0; i+k < n; i++) {
        if (best > rsq(i, i+k)) {
            best = rsq(i, i+k);
            ans = i + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
