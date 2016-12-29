#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v;
    scanf("%d", &v);
    int v2 = v;
    
    vector<int> costs(9);
    int minCost = INT_MAX, minDigit;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &costs[i]);
        if (costs[i] <= minCost) {
            minCost = costs[i];
            minDigit = i+1;
        }
    }
        
    while (v > 0) {
        int m = 0, c = minCost, d = minDigit;
        for (int i = 0; i < 9; i++) {
            int n = (v - costs[i]) / minCost;
            if (n && n >= m) {
                m = n;
                c = costs[i];
                d = i+1;
            }
        }

        if (!m && v < minCost) break;

        v -= c;
        printf("%d", d);
    }
    
    if (v == v2) printf("-1");
    printf("\n");
    
    return 0;
}
