#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> playlist(n);
    vector<int> counter(m + 1, 0);
    
    int minSize = n / m;
    
    for (int i = 0; i < n; i++) {
        cin >> playlist[i];
        if (playlist[i] <= m) {
            counter[playlist[i]]++;
        }
    }
    
    int changes = 0;
    int j = 0;
    for (int band = 1; band <= m; band++) {
        int needed = minSize - counter[band];
        for (; needed > 0; j++) {
            int otherBand = playlist[j];
            if (otherBand > m || counter[otherBand] > minSize) {
                playlist[j] = band;
                changes++;
                needed--;
                if (otherBand <= m && counter[otherBand] > minSize) counter[otherBand]--;
            }
        }
    }
    
    printf("%d %d\n", minSize, changes);
    for (int i = 0; i < n; i++) printf("%d ", playlist[i]);
    printf("\n");
    
    return 0;
}