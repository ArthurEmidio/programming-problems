#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int i = 0;
    int j = s.size() - 1;

    int diff = 0;
    while (i < j) {
        if (s[i] != s[j]) diff++;
        i++, j--;
    }

    printf("%s\n", (diff == 1 || (!diff && s.size() % 2 != 0)) ? "YES" : "NO");

    return 0;
}
