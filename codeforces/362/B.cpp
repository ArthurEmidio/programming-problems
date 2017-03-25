#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string a;
    int b = 0;

    int i = 0;
    while (s[i] != '.') i++;
    i++;
    while (s[i] != 'e') a += s[i++];
    i++;
    while (i < s.size()) b = b*10 + (s[i++] - '0');

    if (a == "0") a.clear();

    string ans;
    ans += s[0];

    i = b;
    int j = 0;
    while (i && j < a.size()) {
        ans += a[j];
        i--, j++;
    }

    while (i) {
        ans += '0';
        i--;
    }

    if (j < a.size()) {
        ans += '.';
        while (j < a.size()) {
            ans += a[j];
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}
