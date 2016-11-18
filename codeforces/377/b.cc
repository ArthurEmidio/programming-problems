#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{    
    int n, k;
    cin >> n >> k;
    
    vector<int> walks(n);
    for (int i = 0; i < n; i++) {
        cin >> walks[i];
    }
    
    int prev = k;
    int changes = 0;
    for (int &w : walks) {
        int acc = prev + w;
        if (acc < k) {
            changes += k - acc;
            w += (k - acc);
        }
        prev = w;
    }
    
    printf("%d\n", changes);
    for (int w : walks) {
        printf("%d ", w);
    }
    printf("\n");
    
    return 0;
}
