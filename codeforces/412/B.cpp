#include <bits/stdc++.h>

using namespace std;

bool found(int s, int j)
{
    int i = (s / 50) % 475;
    for (int k = 0; k < 25; k++) {
        i = (i * 96 + 42) % 475;
        if (26 + i == j) return true;
    }
    return false;
}

int main()
{
    int p, x, y;
    scanf("%d %d %d", &p, &x, &y);

    int curr = x;
    while (curr >= y) {
        if (found(curr, p)) {
            printf("0\n");
            return 0;
        }
        curr -= 50;
    }

    curr = x + 100;
    int ans = 1;
    while (1) {
        if (found(curr, p) || found(curr - 50, p)) {
            printf("%d\n", ans);
            return 0;
        }
        curr += 100;
        ans++;
    }

    return 0;
}
