#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m = max(m, v[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (m - v[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}
