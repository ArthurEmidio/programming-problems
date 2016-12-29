#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, q;
    scanf("%d %d", &n, &q);
    
    vector<int> servers(n);
    for (int i = 0; i < n; i++) servers[i] = 1;
    
    for (int i = 0; i < q; i++) {
        int t, k, d;
        scanf("%d %d %d", &t, &k, &d);
        
        int x = k;
        for (int s : servers) {
            if (s <= t) x--;
            if (!x) break;
        }
        
        if (!x) {
            int sum = 0;
            x = k;
            for (int i = 0; i < n; i++) {
                if (servers[i] <= t) {
                    servers[i] = t + d;
                    x--;
                    sum += i+1;
                }
                if (!x) break;
            }
            printf("%d\n", sum);          
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}
