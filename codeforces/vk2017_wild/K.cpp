#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int i = 0;
    string ans;
    while (i < n) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            int q = 0;
            while (i < n && s[i] == c) i++ , q++;
            ans += c;
            if (q == 2 && (c == 'e' || c == 'o')) ans += c;
        } else {
            ans += c;
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}
