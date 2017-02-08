#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    
    if (sum == 0) {
        bool possible = false;
        int i;
        for (i = 0; i < n-1; i++) {
            if (v[i] != 0) {
                possible = true;
                break;
            }
        }
        
        if (possible) {
            printf("YES\n");
            printf("2\n");
            printf("1 %d\n", i+1);
            printf("%d %d\n", i+2, n);
        } else {
            printf("NO\n");
        }
    } else {
        printf("YES\n");
        printf("1\n");
        printf("1 %d\n", n);
    }
    
    return 0;
}
