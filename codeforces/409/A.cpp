#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int ans = 0;
    int f = 0;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] == 'V' && s[i+1] == 'K') ans++;
        else {
            if ((s[i] == 'V' && (i+2 == s.size() || s[i+2] == 'V')) ||
                ((i-1 < 0 || s[i-1] == 'K') && s[i+1] == 'K')) f = 1;
        }
    }

    cout << (ans + f) << endl;

    return 0;
}
