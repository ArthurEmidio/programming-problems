#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc = 1;
    
    for (;;) {
        int n, m;
        cin >> n >> m;
        if (!n && !m) break;
        
        vector<int> levels(n * m, 0);
        for (int i = 0; i < n * m; i++) {
            cin >> levels[i];
        }
        sort(levels.begin(), levels.end());
        
        int v;
        cin >> v;
        
        int currVol = 0;
        int i;
        for (i = 1; i < levels.size(); i++) {
            int newVol = i * 100 * (levels[i] - levels[i - 1]);
            if (newVol + currVol > v) break;
            currVol += newVol;
        }
        
        double ans = levels[i - 1] + (v - currVol) / (i * 100.0);
        auto it = lower_bound(levels.begin(), levels.end(), ans);
        double count = it - levels.begin();
        
        printf("Region %d\n", tc++);
        printf("Water level is %.2f meters.\n", ans);
        printf("%.2f percent of the region is under water.\n\n", (count / (n*m)) * 100.0);
    }
    
    return 0;
}
