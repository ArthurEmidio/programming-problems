#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int L = 0;
    int R = 0;
    
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
        L += v[i].first;
        R += v[i].second;
    }
    
    int ans = abs(L - R);
    int idx = -1;
    for (int i = 0; i < n; i++) {
        int beauty = abs((L - v[i].first + v[i].second) - (R - v[i].second + v[i].first));
        if (beauty > ans) {
            idx = i;
            ans = beauty;
        }
    }
    
    printf("%d\n", idx+1);
    
    return 0;
}