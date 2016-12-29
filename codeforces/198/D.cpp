#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    
    vector<int> lis(1, v[0]);
    for (int i = 1; i < n; i++) {
        if (v[i] > lis.back()) lis.push_back(v[i]);
        else {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
        }
    }
    
    printf("%lu\n", lis.size());
    
    return 0;
}
