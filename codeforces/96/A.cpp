#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    bool valid = false;
    for (char c : s) {
        if (c == 'H' || c == 'Q' || c == '9') valid = true;
    }

    printf("%s\n", valid ? "YES" : "NO");

    return 0;
}
