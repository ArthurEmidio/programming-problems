#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    sort(v.begin(), v.end());
    
    int ans = numeric_limits<int>::max();
    int i = 0, j = n - 1;
    while (i < n) {
        auto rightIt = lower_bound(v.begin(), v.end(), 2*v[i] + 1);
        int removeRight = v.end() - rightIt;
        ans = min(ans, removeRight + i);
                
        auto leftIt = lower_bound(v.begin(), v.end(), ceil(v[j]/2.0));
        int removeLeft = leftIt - v.begin();
        ans = min(ans, removeLeft + n - j - 1);
                
        i++, j--;
    }
    
    printf("%d\n", ans);
    
    return 0;
}
