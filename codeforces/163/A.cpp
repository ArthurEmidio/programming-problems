#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    int i = 0;
    while (i < n) {
        char c = s[i++];
        while (i < n && s[i] == c) ans++, i++;
    }
    cout << ans << endl;

    return 0;
}
