#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int k, r;
    cin >> k >> r;
    
    int tot = 0;
    int i;
    for (i = 1; ; i++) {
        tot += k;
        if (tot % 10 == 0 || (tot - r) % 10 == 0) {
            break;
        }
    }
    
    cout << i << endl;
    
    return 0;
}
