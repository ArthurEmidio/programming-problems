#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        
        vector<int> seq1(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &seq1[i]);
        }
        
        set<int> seenOnce;
        int j = 0;
        int g1, g2;
        for (int i = 0; i < n; i++) {
            g1 = seq1[i];
            scanf("%d", &g2);
            
            if (g1 != g2) {
                if (seenOnce.count(g1)) {
                    seenOnce.erase(g1);
                } else {
                    seenOnce.insert(g1);
                }
                
                if (seenOnce.count(g2)) {
                    seenOnce.erase(g2);
                } else {
                    seenOnce.insert(g2);
                }
            }
            
            if (seenOnce.empty()) {
                printf("%d-%d ", j+1, i+1);
                j = i + 1;
            }
        }
        printf("\n");
    }
    
    return 0;
}
