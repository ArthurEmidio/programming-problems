#include <bits/stdc++.h>

using namespace std;

int pal(int n)
{
    string s = to_string(n);
    int x;
    if (n > 9) x = s[0] - '0' + (s[1] - '0') * 10;
    else x = (s[0] - '0') * 10;
    return x;
}

int main()
{
    int h, m;
    scanf("%d:%d", &h, &m);

    int nm = pal(h);
    int ans = 0;
    while (nm >= 60 || m > nm) {
        ans += 60 - m;
        m = 0;
        h = (h + 1) % 24;
        nm = pal(h);
    }
    ans += nm - m;

    printf("%d\n", ans);

    return 0;
}
