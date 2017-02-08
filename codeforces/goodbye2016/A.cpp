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
    
    int n, k;
    cin >> n >> k;
    
    int tot = 0;
    int i;
    for (i = 1; i <= n; i++) {
        tot += 5*i;
        if (tot + k > 240) {
            tot -= 5*i;
            i--;
            break;
        }
    }
    
    printf("%d\n", min(i, n));
    
    return 0;
}
