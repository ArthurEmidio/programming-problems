#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    
    ll odd = n % 2 == 0 ? n/2 : (n/2)+1;
    ll even = n/2;
    
    ll ans = k <= odd ? (2*k - 1) : (2*(k-odd));
    cout << ans << endl;
    
    return 0;
}