#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    if (n == 1) cout << -1 << endl;
    else cout << n << " " << n+1 << " " << n*(n+1) << endl;
    
    return 0;
}
