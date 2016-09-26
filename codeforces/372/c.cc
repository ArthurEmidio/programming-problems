#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

bool equals(double x, double y)
{
    return fabs(x - y) <= EPS;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    ll screen = 2;
    for (ll i = 1; i <= n; i++) {
        ll v = i * (i + 1) * (i + 1) - (screen / i);
        printf("%lld\n", v);        
        screen = i * (i + 1);
    }
    
    return 0;
}
