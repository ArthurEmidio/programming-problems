#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    
    ll turns = 0;
    ll prev;
    cin >> prev;    
    for (ll i = 1; i < m; i++) {
        ll a;
        cin >> a;
        if (prev > a) turns++;
        prev = a;
    }
    
    cout << prev-1 + turns*n << endl;
    
    return 0;
}