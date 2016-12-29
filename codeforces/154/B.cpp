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
    
    int ans = 0;
    int i = 0, j = n - 1;
    for (;;) {
        auto begin = v.begin() + i;
        auto end = v.end() - (n-j-1);
        
        int maxMax = v[i] * 2;
        auto rightIt = upper_bound(begin, end, maxMax);
        if (rightIt == end) break;
        int removeRight = end - rightIt;
                
        int minMin = ceil(v[j]/2.0);
        auto leftIt = lower_bound(begin, end, minMin);
        int removeLeft = leftIt - begin;
                
        if (removeRight > removeLeft) i++;
        else j--;
        
        ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}

// 10 15 20 30 40 50
// 10 14 20