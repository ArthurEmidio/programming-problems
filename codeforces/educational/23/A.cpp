#include <bits/stdc++.h>

using namespace std;

bool f(int x, int d, int k)
{
    return (d - x*k) % (2*x) == 0;
}

int main()
{
    int x1, y1, x2, y2, x , y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

    int dx = x2 - x1;
    int dy = y2 - y1;

    bool ans = false;
    if (dx % x == 0 && dy % y == 0) {
        if (dx / x >= dy / y) {
            ans = f(y, dy, dx / x);
        } else {
            ans = f(x, dx, dy / y);
        }
    }

    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}
