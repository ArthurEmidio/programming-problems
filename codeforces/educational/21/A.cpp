#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    if (n < 10) {
        printf("1\n");
        return 0;
    }

    string s = to_string(n);
    string ans;
    if (s[0] == '9') {
        ans = '1' + string(s.size(), '0');
    } else {
        ans = static_cast<char>(s[0] + 1) + string(s.size() - 1, '0');
    }

    cout << stoi(ans) - n << endl;

    return 0;
}
