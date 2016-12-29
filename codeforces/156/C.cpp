#include <bits/stdc++.h>

using namespace std;

int main()
{    
    int n;
    scanf("%d", &n);
    
    map<int, vector<int>> elements;    
    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d", &b);
        elements[b].push_back(i);
    }
    
    int ans = 1;
    for (auto &elm1 : elements) {
        vector<int> &occ1 = elm1.second;
        
        for (auto &elm2 : elements) {    
            vector<int> &occ2 = elm2.second;        
            
            int curr = 1;
            int pos = occ1[0];
            for (;;) {
                auto next2 = upper_bound(occ2.begin(), occ2.end(), pos);
                if (next2 == occ2.end()) break;
                pos = *next2;
                curr++;
                
                auto next1 = upper_bound(occ1.begin(), occ1.end(), pos);
                if (next1 == occ1.end()) break;
                pos = *next1;
                curr++;
            }
            
            ans = max(curr, ans);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
