#include <bits/stdc++.h>

using namespace std;

int main()
{    
    ios_base::sync_with_stdio(false);
    
    int n, k;
    scanf("%d %d", &n, &k);
    
    vector<int> dists, neg;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t < 0) {
            if (!neg.empty() && neg.back() != i-1) dists.push_back(i - neg.back() - 1);            
            neg.push_back(i);
        }
    }
    
    if (neg.size() > k) {
        printf("-1\n");
        return 0;
    }
    
    bool gotFinal = false;
    int finalDist = 0;
    if (!neg.empty() && neg.back() != n-1) {
        finalDist = n - neg.back() - 1;
        dists.push_back(finalDist);
    }
    
    sort(dists.begin(), dists.end());
        
    int ans = neg.empty() ? 0 : 1;        
    int rem = k - neg.size();        
    int sum = 0;
    for (int d : dists) sum += d;
    
    while (sum > rem) {
        int d = dists.back();
        sum -= d;
        dists.pop_back();
            
        if (d == finalDist && !gotFinal) gotFinal = true, ans++;
        else if (sum <= rem && d > finalDist && sum+d-finalDist <= rem) ans++;
        else ans += 2;
    }
        
    printf("%d\n", ans);
    
    return 0;
}
