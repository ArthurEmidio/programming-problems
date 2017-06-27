#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    bool changed = false;
    bool nonIncreasing = true;

    int prev = INT_MAX;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a != b) changed = true;
        if (a > prev) nonIncreasing = false;
        prev = a;
    }

    if (changed) {
        printf("rated\n");
    } else {
        printf("%s\n", nonIncreasing ? "maybe" : "unrated");
    }

    return 0;
}
