#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main()
{
    string s;
    cin >> s;

    ll bs = 0;
    ll ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'b') {
            bs = (bs + 1) % MOD;
        } else {
            ans = (ans + bs) % MOD;
            bs = (bs * 2) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
