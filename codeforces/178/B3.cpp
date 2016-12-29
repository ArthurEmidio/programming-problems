#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);    
    
    int bw = 0;
    vector<int> b1, b2;
    for (int i = 0; i < n; i++) {
        int t, w;
        scanf("%d %d", &t, &w);
        if (t == 1) b1.push_back(w);
        else b2.push_back(w);
    }
    
    sort(b1.begin(), b1.end(), std::greater<int>());
    sort(b2.begin(), b2.end(), std::greater<int>());
    
    int w1 = 0;
    for (int x : b1) w1 += x;
    int ans = INT_MAX;
    for (int i = 0; i <= b1.size(); i++) {
        int w2 = 0;
        for (int x : b2) w2 += x;
        
        for (int j = 0; j <= b2.size(); j++) {
            if (i + 2*j >= w1+w2) ans = min(ans, i + 2*j);
            if (j < b2.size()) w2 -= b2[j];
        }
        
        if (i < b1.size()) w1 -= b1[i];
    }
    
    printf("%d\n", ans);
    
    return 0;
}
