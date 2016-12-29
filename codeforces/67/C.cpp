#include <bits/stdc++.h>

using namespace std;

vector<int> divisors(int n)
{
    vector<int> ans;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            ans.push_back(n/i);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int a, b;
    scanf("%d %d", &a, &b);
    
    vector<int> ad = divisors(a);
    vector<int> bd = divisors(b);
    set<int> ad_set(ad.begin(), ad.end());
    vector<int> common;
    for (int x : bd) {
        if (ad_set.count(x)) {
            common.push_back(x);
        }
    }
    
    sort(common.begin(), common.end());
          
    int n;
    scanf("%d", &n);
    
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int l, h;
        scanf("%d %d", &l, &h);
        
        auto it = lower_bound(common.begin(), common.end(), h);
        if (it == common.end()) it = prev(it);
        
        if (*it >= l && *it <= h) {
            ans[i] = *it;
        } else if (it == common.begin()) {
            ans[i] = -1;
        } else {
            int p = *prev(it);
            if (p >= l && p <= h) ans[i] = p;
            else ans[i] = -1;
        }
    }
    
    for (int x : ans) printf("%d\n", x);
    
    return 0;
}
