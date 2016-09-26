#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    
    pair<ll, ll> pos(0, 0);
    for (char c : s) {
        if (c == 'L') pos.first--;
        else if (c == 'R') pos.first++;
        else if (c == 'U') pos.second++;
        else pos.second--;
    }
      
    ll x = abs(pos.first) + abs(pos.second);
    printf("%lld\n", (x % 2 == 0) ? (x / 2) : -1);
    
    return 0;
}
